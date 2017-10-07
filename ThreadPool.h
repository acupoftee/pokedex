#ifndef NIXHOPOOL
#define NIXHOPOOL

#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <queue>

using namespace std;

/**
*  ThreadPool, an alternative to ExecutorService on Java, for C++.
*  Enabling Workers in C++.
*
*  This class requires a number of C++11 features to be included
*  into your compiler.
*/

class ThreadPool
{
public:
	explicit ThreadPool(int thread_amt) :
		jobsRmdr_(0),
		quit_(false)
	{
		_threads = vector<thread>(thread_amt);

		for (int index = 0; index < thread_amt; ++index)
		{
			_threads[index] = move(thread([this]
			{
				this->Task();
			}));
		}
	}

	/**
	*  JoinAll on deconstruction
	*/
	~ThreadPool()
	{
		JoinAll(); // Destroy all them threads
	}

	/**
	*  Adds a new job to the pool, and if there are no jobs in the queue,
	*  a thread is called to take the job. If all threads are busy,
	*  the job is added to the end of the queue to await for execution.
	*/
	void AddJob(function<void(void)> job)
	{
		// scoped lock
		{
			lock_guard<mutex> lock(queueMutex_);
			_queue.emplace(job);
		}
		// scoped lock
		{
			lock_guard<mutex> lock(jobsRmdr_Mutex);
			++jobsRmdr_;
		}
		jobAvailableCVar_.notify_one();
	}

	/**
	*  Join with all threads. Block until all threads have completed.
	*  The queue may be filled after this call, but the threads will
	*  be done. 
	*
	*  After invoking `ThreadPool::JoinAll`, the pool can no
	*  longer be used.
	*/
	void JoinAll()
	{
		// scoped lock
		{
			lock_guard<mutex> lock(queueMutex_);
			if (quit_)
			{
				return;
			}
			quit_ = true;
		}

		// note that we're done, and wake up any thread that's
		// waiting for a new job
		jobAvailableCVar_.notify_all();

		for (auto& x : _threads)
		{
			if (x.joinable())
			{
				x.join();
			}
		}
	}

	/**
	*  Wait for the pool to empty before continuing.
	*  This does not call `thread::join`, it only waits until
	*  all jobs have finished executing.
	*/
	void WaitAll()
	{
		unique_lock<mutex> lock(jobsRmdr_Mutex);
		if (jobsRmdr_ > 0)
		{
			waitCVar_.wait(lock, [this]
			{
				return jobsRmdr_ == 0;
			});
		}
	}

private:
	/**
	*  Retrieve the upcoming job in queue to run it and
	*  notify the main thread that a job has been accomplished.
	*/
	void Task()
	{
		while (true)
		{
			function<void(void)> job;

			// scoped lock
			{
				unique_lock<mutex> lock(queueMutex_);

				if (quit_)
				{
					return;
				}

				// Wait for a job if we don't have any.
				jobAvailableCVar_.wait(lock, [this]
				{
					return _queue.size() > 0 || quit_;
				});

				if (quit_)
				{
					return;
				}

				// Get job from the queue
				job = _queue.front();
				_queue.pop();
			}

			job();

			// scoped lock
			{
				lock_guard<mutex> lock(jobsRmdr_Mutex);
				--jobsRmdr_;
			}

			waitCVar_.notify_one();
		}
	}

	vector<thread> _threads;
	queue<function<void(void)>> _queue;

	int jobsRmdr_; // Remainder jobs
	bool quit_; // To get out of the current thing or not?
	condition_variable jobAvailableCVar_;
	condition_variable waitCVar_;
	mutex jobsRmdr_Mutex;
	mutex queueMutex_;
};

#endif //NIXHOPOOL