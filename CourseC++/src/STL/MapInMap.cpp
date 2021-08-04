#include "MapInMap.h"

void MapInMap::RunExercise()
{
    std::cout
        << "\n=====================================================\n\t\tMap in Map\n";
    std::map<int, std::map<int, int>> map2DTest;

    std::map<int, int> temp;

    temp.insert(std::make_pair(10, 200));

    map2DTest.insert(std::make_pair(50, temp));
    map2DTest.insert(std::make_pair(52, temp));
    map2DTest.insert(std::make_pair(40, temp));
    map2DTest.insert(std::make_pair(52, temp));
    map2DTest.insert(std::make_pair(53, temp));
    map2DTest.insert(std::make_pair(54, temp));

    std::map<int, std::map<int, int>>::iterator itr;
    std::map<int, int>::iterator itr2;

    for (itr = map2DTest.begin(); itr != map2DTest.end(); itr++)
    {
        for (itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
        {
            std::cout << "\nFirst Map's Key:\t" << itr->first
                      << "\nInner maps' Key: " << itr2->first
                      << " Value: " << itr2->second;
        }
    }

    std::cout << "\n=====================================================\n";
}
