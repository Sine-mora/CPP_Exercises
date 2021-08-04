#include "UnorderedSets.h"

/* Associative Container
 *
 * std::set<object_type> set_name = {10,40,50..}
 *
 * Set is an associative container that contains
 * a set of unique objects.
 *
 * Sets are usually implemented as red-black trees
 * (Self-balancing binary search tree)
 *
 * Constant time complexity
 *
 * Container elements may not be modified.
 */

void UnorderedSet::RunExercise()
{
    std::cout << "\n==================================================\n\t\tSet\n";
    std::unordered_set<int> unorderedSetTest = {10, 40, 10, 20, 50};

    unorderedSetTest.insert(70);
    for (const auto& i : unorderedSetTest)
    {
        std::cout << "Set size: " << unorderedSetTest.size() << " : "<<i<<"\n";
    }

    std::cout << "\n==================================================\n";
}
