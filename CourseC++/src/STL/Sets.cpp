#include "Sets.h"

/* Associative Container
 *
 * std::set<object_type> set_name = {10,40,50..}
 *
 * Set is an associative container that contains
 * a sorted set of unique objects.
 *
 * 10,40,10,20,50 -> Set = {10,20,40,50}
 *
 * Sets are usually implemented as red-black trees
 * (Self-balancing binary search tree)
 *
 * Search, removal and insertion operations have logarithmic complexity
 */

void Set::RunExercise()
{
    std::cout << "\n==================================================\n\t\tSet\n";
    std::set<int> setTest = {10, 40, 10, 20, 50};

    setTest.insert(50);
    for (const auto& i : setTest)
    {
        std::cout << "Set size: " << setTest.size() << " : "<<i<<"\n";
    }

    std::cout << "\n==================================================\n";
}
