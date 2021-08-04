#include "UnorderedMaps.h"

/*  Unordered Associative Container
 *
 *  Contains unsorted Key-Value Pair
 *
 *  UnorderedMap CAN'T have duplicate Key-Value pairs
 *
 *  We CAN insert/delete AND alter the value.
 */

void UnorderedMap::RunExercise()
{
    std::cout << "\n=================================================================\n";
    std::cout << "\nUnordered Map\n";

    std::unordered_map<int, std::string> unorderedMapTest1;
    std::unordered_map<int, std::string> unorderedMapTest2 = {
        {150, "Ved"}, {72, "Tim"}, {180, "Faran"}};
    std::unordered_map<int, std::string> unorderedMapTest3 = {
        {150, "Ved"}, {72, "Tim"}, {180, "Faran"}};

    for (const auto& i : unorderedMapTest2)
    {
        unorderedMapTest1.insert(std::make_pair(i.first, i.second));
        std::cout << "\nMap2:Key - Value: " << i.first << " - " << i.second << "\n";
        std::cout << "\nMap1: Key-Value.at(): " <<unorderedMapTest1.at(i.first) <<"\n";
        std::cout << "\nMap2: " << unorderedMapTest2[150]
                  << "Size: " << unorderedMapTest2.size()
                  << " count 150: " << unorderedMapTest2.count(150) << "\n";
        unorderedMapTest3.erase(0);

    }
    unorderedMapTest1.swap(unorderedMapTest2);
    unorderedMapTest1.clear();

    std::cout
        << "\n\n=================================================================\n";
}
