#include "PriorityQueue.h"
#include "Job.h"

class JobQueue
{
    private:

    //a PriorityQueue containing Job objects
    PriorityQueue<Job> job_queue;

    public:

    JobQueue()
    :
    job_queue{}
    {
    }

    //inserts a Job into the JobQueue
    void insert(Job job)
    {
        job_queue.insert(job);
    }

    //runs the highest priority Job in the JobQueue, which is defined to be
    //the Job with the largest priority number
    void runHighestPriority()
    {
        //execute the highest priority job
        job_queue.max().execute();
        //and then remove it
        job_queue.remove_max();
    }
};
