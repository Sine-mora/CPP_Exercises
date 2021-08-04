#include "MultiSets.h"

/* Multiset is an associative container that contains
 * ordered set that can have duplicate objects
 *
 * std::multiset<int> multiSet = {10,40,10,40,50}
 */

void MultiSet::RunExercise()
{
    std::cout <<"\n================================================\n\t\tMulti Set\n";
    std::multiset<int> multiSet = {10,40,10,40,50};
    multiSet.insert(10);

    for(const auto& i :multiSet)
    {
        std::cout <<"\nValue: " << i;
    }

    std::cout <<"\nFind 10 in multiset:] Size: " <<multiSet.size();
    multiSet.insert(1);
    multiSet.find(10);


    std::cout <<"\n================================================\n";
}
