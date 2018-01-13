#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <numeric>

#include "ThreadPool.h"

int task(int msg_num,
	 int& send_count,
	 std::mutex& mutex,
	 std::queue<std::string>& msg_queue,
	 std::condition_variable& condition)
{
    std::thread::id tid = std::this_thread::get_id();
    std::stringstream ss;
    ss << tid;

    int i=0;
    for(; i<msg_num; i++)
    {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	{
	    std::unique_lock<std::mutex> lock(mutex);
	    std::string msg = ss.str() + "_i" + std::to_string(i);
	    msg_queue.emplace(msg);

	    send_count++;
	    std::cout << "send msg[" << send_count << "] : " << msg << std::endl;
	}

	condition.notify_one();
    }
    return i;
}

int main()
{
    // 1. define variables for send/recv messages
    std::mutex msg_mutex;
    std::queue<std::string> msg_queue;
    std::condition_variable condition;
    int send_count(0); // "std::atomic<int>" is also OK


    // 2. define message numbers which will be sent from subthreads
    std::vector<int> messages = {1,2,3,4,5};
    int total_message = std::accumulate(messages.begin(), messages.end(), 0);
    std::cout << "total_message : " << total_message << std::endl;


    // 3. create and start ThreadPool
    ThreadPool pool(3);
    std::vector<std::future<int>> results;
    for (auto m : messages) {
	auto res = pool.enqueue(task, m,
				std::ref(send_count),
				std::ref(msg_mutex),
				std::ref(msg_queue),
				std::ref(condition));
	results.push_back(std::move(res));
    }


    // 4. recieve messages from subthreads and update progress counter
    int recv_count(0);
    while (recv_count < total_message) {

	{
	    std::unique_lock<std::mutex> lock(msg_mutex);
	    condition.wait(lock);
	    while (!msg_queue.empty()) {

		std::string msg = std::move(msg_queue.front());
		msg_queue.pop();

		recv_count++;
		double k = 100.0*(double)recv_count/(double)total_message;

		std::cout << "recv msg[" << recv_count << "] : " << msg;
		std::cout << ", " << k << "% progressed."<< std::endl;

		// if error happen, exit while loops.
		/*
		if (msg == "error")
		{
		    recv_count = total_message;
		    break;
		}
		*/
	    }
	}
    }


    // 5. get result of each task
    for (auto& res : results) {
	std::cout << "result : " << res.get() << std::endl;
    }
    
    return 0;
}
