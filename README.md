# multi-thread progress : example.cpp

This is a sample code to display calculation progress under C++11 thread-pool environment(ThreadPool.h).
Subthreads send messages to a main-thread and a number of recived messages in a main-thread is progress of calculation in all subthreads.
Logic of this code is almost same with the ThreadPool's task-queue.

Thanks to authers of the ThreadPool.h
<https://github.com/bilash/threadpool>
