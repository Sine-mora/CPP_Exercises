#include "Stacks.h"
/*  Adaptor Container
 *
 *  It is replication of STACK data structure
 *
 *  Insertion / Deletion is performed at the top
 *  Last In, First Out
 *
 *  std::stacl<object_type> stack_name;
 *
 */

void Stack::RunExercise()
{
    std::stack<int> stackTestStack; // Initial size = 0

    std::cout
        << "\n====================================================================\n";
    std::cout << "\nstd::stack<int> stackTestStack; // Initial size = 0\n";
    std::cout << "\nFunctions:\n";

    stackTestStack.push(6);
    std::cout << "\n1. stackTestStack.push(element);\n\t- Insert an element at the end of "
                 "the list. Copies the value.\n";

    std::cout <<"\n2. stackTestStack.top() : - Gets the top element\n\t"<<stackTestStack.top();

    stackTestStack.pop();
    std::cout<<"\n3. stackTestStack.pop(); - Removes the top element.";

    std::cout
        << "\n4.vTestVector2.size(); :\n\t" << stackTestStack.size()
        << "\n\t- Returns the number of elements present in the list.\n"
           "\n====================================================================\n";
}
