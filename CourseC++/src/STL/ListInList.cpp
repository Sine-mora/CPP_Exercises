#include "ListInList.h"

void NestedLists::RunExercise()
{
    std::cout << "\n===========================================\n\t\tNested Lists\n";

    std::list<int> listTest = {7, 8, 9};
    std::list<std::list<int>> NestedList = {{1, 2, 3}, {4, 5, 6}};

    NestedList.push_back(listTest);

    std::list<std::list<int>>::iterator itr = NestedList.begin();

    for(; itr != NestedList.end(); itr++)
    {
        std::list<int> pi = *itr;

        std::list<int>::iterator itr2 = pi.begin();

        for(; itr2 != pi.end(); itr2++)
        {
            std::cout << *itr2;
        }
        std::cout << "\n";
    }

    std::cout << "\n===========================================\n";
}
