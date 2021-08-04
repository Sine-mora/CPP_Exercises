#include "Arrays.h"

/*  std::array<T,N> arr_name;
 *
 *  Arrays are fixed in size sequence containers
 *  They cannot be expanded or contracted dynamically
 *
 *  Properties:
 *  Sequence ; Contiguous storage.
 */

void STDArray::RunExercise()
{
    std::array<int, 3> arrTestArray1;
    std::array<int, 3> arrTestArray2 = {10, 20, 30};

    // Functions :
    std::cout << "\n================================================================="
                 "\nAvailable Functions for std::array<int,3> TestArray = {10,20,30}; "
                 "\n\nstd::array<int,3> TestArray1; //non initialized"
                 "\nnumber = 2\n";

    std::cout << "\n1.TestArray.at(number) :\n\t" << arrTestArray2.at(2);
    std::cout << "\n2.TestArray[number] :\n\t" << arrTestArray2[2];
    std::cout << "\n3.TestArray.front() :\n\t" << arrTestArray2.front();
    std::cout << "\n4.TestArray.back() :\n\t" << arrTestArray2.back();
    arrTestArray2.fill(0);
    std::cout << "\n5.TestArray.fill(0) - Fills entire array with 0s:\n\t"
              << arrTestArray2.at(0) << ", " << arrTestArray2.at(1) << ", "
              << arrTestArray2.at(2);

    arrTestArray1.swap(arrTestArray2);
    std::cout << "\n6.TestArray1.swap(TestArray) - Swaps values of two arrays:\n\t"
              << arrTestArray2.at(2);
    arrTestArray2.empty();
    std::cout << "\n7.TestArray.empty() - Empties the array: \n\t";
    std::cout << "\n8.TestArray.size() :\n\t" << arrTestArray2.size();
    std::cout << "\n9.TestArray.max_size() :\n\t" << arrTestArray2.max_size();
    std::cout << "\n=================================================================\n";
}
