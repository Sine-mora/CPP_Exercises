#include "Queues.h"

/*  Adaptor container
 *
 *  Queue container replicates QUEUE data structure
 *
 *  Insertion is done at back and
 *  Deletion is done at front
 *
 *  First In, First Out
 *
 *  queue<object_type> queue_name;
 */

void Queue::RunExercise()
{
    std::queue<int> queueTest;

    std::cout <<"\n========================================================\nQueues:";
    queueTest.push(10);
    queueTest.push(9);
    queueTest.front();
    queueTest.back();
    queueTest.pop();
    queueTest.size();

    std::cout <<"\n=========================================================\n";
}
