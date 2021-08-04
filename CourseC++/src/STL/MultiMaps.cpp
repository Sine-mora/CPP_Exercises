#include "MultiMaps.h"

/*  Associative Container
 *  Elements are sorted
 *
 *  Contains sorted Key-Value Pair
 *
 *  MultiMap can have duplicate Key-Value pairs
 *
 *  We can insert/delete the value, but can't alter it.
 *
 *  1001 Tim
 *  1001 Rick
 */

void MultiMap::RunExercise()
{
    std::cout <<"\n=================================================================\n";
    std::cout <<"\nMultiMap\n";

    std::multimap<int, std::string> multiMapTest1;
    std::multimap<int, std::string> multiMapTest2 = {
        {150, "Ved"}, {201, "Tim"}, {201, "Faran"}};

    std::cout << "Elements count with number 201: " << multiMapTest2.count(201)<<"\n";

    auto i = multiMapTest2.begin();

    for (; i != multiMapTest2.end(); i++)
    {
        std::cout <<"Map2 Keys and values: "<<i->first << " " << i->second <<"\n";

        multiMapTest1.insert(std::pair<int, std::string>(106, "Amit"));
        multiMapTest1.insert(std::make_pair(208, "Hina"));

        multiMapTest2.erase(i);

    }
    multiMapTest1.swap(multiMapTest2);
    multiMapTest2.clear();
    std::cout << "Elements count with number 201: " << multiMapTest1.count(201)
              << "\nMultiMap 1 and 2 sizes: " << multiMapTest1.size() << " and "
              << multiMapTest2.size();
    std::cout <<"\n\n=================================================================\n";
}
