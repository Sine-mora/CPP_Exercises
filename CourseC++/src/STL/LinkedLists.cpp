#include "LinkedLists.h"
/* Container
 *
 *  std::list<object_type> list_name;
 *
 */

void List::RunExercise()
{
    std::list<int> listTestList1; // Initial size = 0
    std::list<int> listTestList2 = {1, 3, 5, 2, 4};

    std::cout
        << "\n====================================================================\n";
    std::cout << "\nstd::vector<int> listTestList1; // Initial size = 0\n"
                 "std::vector<int> listTestList2 = {1,3,5,2,4}\n";
    std::cout << "\nFunctions:\n";

    std::cout << "\n==================================================================\n";
    std::cout << "||\t\tIterator - It is a  pointer to a container!\t ||\n"
                 "\n||\t\tlist<int>::iterator i = vec.begin();\t\t ||";
    std::cout << "\n==================================================================\n";

    listTestList2.push_back(6);
    std::cout << "\n1.listTestList2.push_back(element);\n\t- Insert an element at the end of "
                 "the list. Copies the value.\n";

    listTestList2.insert(listTestList2.begin(), 8);
    std::cout << "\n3.listTestList2.insert(listTestList2.begin(),8);\n\t- .begin() returns "
                 "iterator \n"
                 "\t- Inserts the element in vector before the position poited by the "
                 "iterator.\n";

    listTestList2.push_front(10);
    std::cout <<"\n.Push_front(10);\n";

    listTestList2.pop_back();
    std::cout << "\n2.listTestList2.pop_back();\n\t- Pop out the last element.\n";

    listTestList2.pop_front();
    std::cout <<"\n.Pop_front();\n";

    listTestList2.reverse();
    std::cout <<"\n.Reverse();\n";

    listTestList1.swap(listTestList2);
    std::cout << "\n6.vTestVector1.swap(vtestVector2); \n\t- Interchanges values of two "
                 "vectors.\n";

    listTestList1.swap(listTestList2);
    listTestList2.sort();
    std::cout <<"\n.Sort()\n";

    listTestList2.merge(listTestList1);
    std::cout <<"\n.Merge(List)\n";

    listTestList2.erase(listTestList2.begin(), listTestList2.end());
    std::cout
        << "\n4.vTestvector2.erase(iterator)\n\t- Remove the element pointed by the "
           "iterator or multiple elements:\n"
           "\n5.vTestVector2.erase(vTestVector2.begin(), vTestVector2.end()-1);\n\t- All "
           "elements but the last.\n";


    std::cout
        << "\n7.vTestVector2.size(); :\n\t" << listTestList2.size()
        << "\n\t- Returns the number of elements present in the list.\n"
           "\n====================================================================\n";
}
