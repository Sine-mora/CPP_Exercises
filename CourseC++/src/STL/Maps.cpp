#include "Maps.h"

/*  Associative (sorted) container
 *
 *  Contains sorted KEY - VALUE pair
 *
 *  Each key is unique and can't change. We can insert / delete, but can't alter.
 *
 *  KEY - VALUE
 *  1001 - Vedinesh
 *  1002 - Tim
 *  1003 - Rick ...
 *
 *  std::map<Key_type, Value_type> map_name;
 */

void Map::RunExercise()
{
    std::map<int, std::string> mapTest1;
    std::map<int, std::string> mapTest2 = {{101, "Vedinesh"}, {201, "Tim"}, {301, "Ben"}};

    // Functions:
    std::cout << "\n====================================================================="
                 "==========================\n";

    std::cout << "\nAvailable Functions for std::map<int,std::string> mapTest2 = "
                 "{{101,\"Vedinesh\"},{201,\"Tim\"}, {301, \"Ben\"}};";
    std::cout << "\nstd::map<int,std::string>mapTest1; // non-initialized";
    mapTest2[201] = "Kevin";
    std::cout << "\nChanging value for key - mapTest2[201] = \"Kevin\"";

    std::cout << "\nIterating map elements:\n";
    for (std::map<int, std::string>::iterator i = mapTest2.begin(); i != mapTest2.end();
         i++)
    {
        // Print map key
        std::cout << "\ni -> first : " << i->first << " ";

        // Print map value
        std::cout << "\ni -> second : " << i->second;
    }

    std::cout << "\n\n1.mapTest2.at(201); :"
              << " -Get Value by key. Out-of-range safe.\n\t" << mapTest2.at(201);
    std::cout << "\n2.mapTest2[201];    :"
              << " - -//-  . Not safe.\n\t" << mapTest2[201];

    std::cout << "\n.insert - insert key,value pair at particular location as the map is "
                 "sorted. Two approaches:\n";

    mapTest2.insert(std::pair<int, std::string>(106, "Amit"));
    std::cout << "\n\t3.mapTest2.insert(std::pair<int,std::string>(106,\"Amit\");\n";

    mapTest2.insert(std::make_pair(208, "Hina"));
    std::cout << "\n\t4.mapTest2.insert(std::make_pair(208, \"Hina\"));\n";

    std::map<int, std::string>::iterator i = mapTest2.begin();
    mapTest2.erase(i);
    std::cout << "\n.erase() - Remove entry in map pointed by iterator.\n"
                 "\n\t5.std::map<int,std::string>::iterator i = mapTest2.begin();"
                 "\n\tmapTest2.erase(i);";
    std::cout << "\n====================================================================="
                 "==========================\n";
}
