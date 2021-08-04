#include "PriorityQueues.h"

#include <vector>
#include <functional>

/*  Adaptor container
 *
 *  It is same as Queue
 *
 *  Replicate MAX HEAP
 *  - Highest element in root node
 *
 *  or MIN HEAP
 *  - The smallest element in the root node
 *
 *  In Priority Queue  - The Greates or Smallest elelemnt is at front
 *
 *  priority_queue<object_type> queue_name;
 */

void PriorityQueue::RunExercise()
{
    std::priority_queue<int> queueTest; //Max Heap
    //std::priority_queue<int, std::vector<int> std::greater<int> >queueTest2;

    std::cout <<"\n========================================================\nPriority Queues:\n";
    queueTest.push(10);
    queueTest.push(90);
    queueTest.push(45);
    queueTest.pop();
    queueTest.size();
    queueTest.empty();

    std::cout <<"\n=========================================================\n";
}
