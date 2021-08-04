#include "Vectors.h"

/* Sequence container - Dynamic array
 *
 *  std::vector<object_type> vector_name;
 *
 *  Vectors expand double in size 1-2-4-8-16-32...
 *
 *  Vectors and Arrays are contiguous containers.
 * -> They store data on cotinuous memory.
 * -> insertion and deletion is very costly.
 */

void Vector::RunExercise()
{
    std::vector<int> vTestVector1; // Initial size = 0
    std::vector<int> vTestVector2 = {1, 3, 5, 2, 4};

    std::cout
        << "\n====================================================================\n";
    std::cout << "\nstd::vector<int> vTestVector1; // Initial size = 0\n"
                 "std::vector<int> vTestVector2 = {1,3,5,2,4}\n";
    std::cout << "\nFunctions:\n";
    std::cout << "\nvTestVector1.at(2):\n\t" << vTestVector2.at(2);
    std::cout << "\nvTestVector2.size():\n\t" << vTestVector2.size();
    std::cout << "\nvTestVector[2]:\n\t" << vTestVector2[2];

    std::cout << "\n==================================================================\n";
    std::cout << "||\t\tIterator - It is a  pointer to a container!\t ||\n"
                 "\n||\t\tvector<int>::iterator i = vec.begin();\t\t ||";
    std::cout << "\n==================================================================\n";

    vTestVector2.push_back(6);
    std::cout << "\n1.vTestVector.push_back(element);\n\t- Insert an element at the end of "
                 "the vector. Copies the value.\n";

    vTestVector2.pop_back();
    std::cout << "\n2.vTestVector.pop_back();\n\t- Pop out the last element.\n";

    vTestVector2.insert(vTestVector2.begin(), 8);
    std::cout << "\n3.vTestVector2.insert(vTestVector2.begin(),8);\n\t- .begin() returns "
                 "iterator \n"
                 "\t- Inserts the element in vector before the position poited by the "
                 "iterator.\n";

    vTestVector2.erase(vTestVector2.begin(), vTestVector2.end() - 1);
    std::cout
        << "\n4.vTestvector2.erase(iterator)\n\t- Remove the element pointed by the "
           "iterator or multiple elements:\n"
           "\n5.vTestVector2.erase(vTestVector2.begin(), vTestVector2.end()-1);\n\t- All "
           "elements but the last.\n";

    vTestVector1.swap(vTestVector2);
    std::cout << "\n6.vTestVector1.swap(vtestVector2); \n\t- Interchanges values of two "
                 "vectors.\n";

    std::cout
        << "\n7.vTestVector2.capacity(); :\n\t" << vTestVector2.capacity()
        << "\n\t- Returns the number of elements that can be "
           "inserted in the vector based on the memory allocated to the vector\n"
           "\n====================================================================\n";
}
