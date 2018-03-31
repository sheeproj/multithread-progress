## multi-thread progress : example.cpp

This is a sample code to display calculation progress under C++11 thread-pool environment(ThreadPool.h).
Subthreads send messages to a main-thread and number of recived messages in a main-thread is calculation progress in all subthreads.
Logic of this code is almost same with the ThreadPool's task-queue.

Thanks to authers of the ThreadPool.h
<https://github.com/bilash/threadpool>


## Build

```bash
$ g++ -std=c++11 -pthread example.cpp
```

## Run

```bash
$ ./a.out 
total_message : 15
send msg[1] : 140506670978816_i0
send msg[2] : 140506662586112_i0
send msg[3] : 140506654193408_i0
recv msg[1] : 140506670978816_i0, 6.66667% progressed.
recv msg[2] : 140506662586112_i0, 13.3333% progressed.
recv msg[3] : 140506654193408_i0, 20% progressed.
send msg[4] : 140506670978816_i0
send msg[5] : 140506662586112_i1
recv msg[4] : 140506670978816_i0, 26.6667% progressed.
recv msg[5] : 140506662586112_i1, 33.3333% progressed.
send msg[6] : 140506654193408_i1
recv msg[6] : 140506654193408_i1, 40% progressed.
send msg[7] : 140506670978816_i1
recv msg[7] : 140506670978816_i1, 46.6667% progressed.
send msg[8] : 140506662586112_i0
send msg[9] : 140506654193408_i2
recv msg[8] : 140506662586112_i0, 53.3333% progressed.
recv msg[9] : 140506654193408_i2, 60% progressed.
send msg[10] : 140506670978816_i2
recv msg[10] : 140506670978816_i2, 66.6667% progressed.
send msg[11] : 140506662586112_i1
recv msg[11] : 140506662586112_i1, 73.3333% progressed.
send msg[12] : 140506670978816_i3
recv msg[12] : 140506670978816_i3, 80% progressed.
send msg[13] : 140506662586112_i2
recv msg[13] : 140506662586112_i2, 86.6667% progressed.
send msg[14] : 140506662586112_i3
recv msg[14] : 140506662586112_i3, 93.3333% progressed.
send msg[15] : 140506662586112_i4
recv msg[15] : 140506662586112_i4, 100% progressed.
result : 1
result : 2
result : 3
result : 4
result : 5
```
