#include "Arrays/Arrays.h"
#include "Exceptions/Exception.h"
#include "Functions/Functions.h"
#include "Loops/Loops.h"
#include "Objects/ATM.h"
#include "Person/Person.h"
#include "ReadingWritingFile/ReadFile.h"
#include "ReadingWritingFile/WriteFile.h"
#include "STL/Arrays.h"
#include "STL/LinkedLists.h"
#include "STL/ListInList.h"
#include "STL/MapInMap.h"
#include "STL/Maps.h"
#include "STL/MultiMaps.h"
#include "STL/MultiSets.h"
#include "STL/PriorityQueues.h"
#include "STL/Queues.h"
#include "STL/Sets.h"
#include "STL/Stacks.h"
#include "STL/UnorderedMaps.h"
#include "STL/UnorderedSets.h"
#include "STL/VectorInVector.h"
#include "STL/Vectors.h"
#include "Structs/Structs.h"
#include "Templates/Templates.hpp"
#include "BudgetAgario/mainLoop.h"
#include "Utils/Timer.h"
#include <iostream>
#include <memory>
#include <vector>

std::vector<std::shared_ptr<IExercise>> FillExercises()
{
    std::vector<std::shared_ptr<IExercise>> vExercises = {};
    vExercises.emplace_back(std::make_shared<Loops>());
    vExercises.emplace_back(std::make_shared<Person>());
    vExercises.emplace_back(std::make_shared<Arrays>());
    vExercises.emplace_back(std::make_shared<Functions>());
    vExercises.emplace_back(std::make_shared<Phone>());
    vExercises.emplace_back(std::make_shared<ATM>());
    vExercises.emplace_back(std::make_shared<ReadFromFile>());
    vExercises.emplace_back(std::make_shared<WriteToFile>());
    vExercises.emplace_back(std::make_shared<Exception>());
    vExercises.emplace_back(std::make_shared<STDArray>());
    vExercises.emplace_back(std::make_shared<Vector>());
    vExercises.emplace_back(std::make_shared<Map>());
    vExercises.emplace_back(std::make_shared<List>());
    vExercises.emplace_back(std::make_shared<Stack>()); // 13
    vExercises.emplace_back(std::make_shared<Queue>());
    vExercises.emplace_back(std::make_shared<PriorityQueue>());
    vExercises.emplace_back(std::make_shared<MultiMap>());
    vExercises.emplace_back(std::make_shared<UnorderedMap>());
    vExercises.emplace_back(std::make_shared<Set>());
    vExercises.emplace_back(std::make_shared<UnorderedSet>());
    vExercises.emplace_back(std::make_shared<MultiSet>());
    vExercises.emplace_back(std::make_shared<TemplateFuncExample>());
    vExercises.emplace_back(std::make_shared<TemplateClassExample<int>>());
    vExercises.emplace_back(std::make_shared<MapInMap>());
    vExercises.emplace_back(std::make_shared<NestedLists>());
    vExercises.emplace_back(std::make_shared<NestedVectors>());
    vExercises.emplace_back(std::make_shared<GameLoop>());

    std::shared_ptr<Loops> TESTNAME;
    TESTNAME = std::make_shared<Loops>();

    /*   Person p;
       if(p.ParseXML())
       {
           p.PrintUsers();
       }*/

    /*
    Phone moto;
    moto.m_cCamera.m_nRear = 10;
    moto.m_cCamera.m_nFront = 5;

    Phone moto2 = Phone{"Potato", 120, 20, "AMD", {13, 6}};

    std::cout << "\nPhone's rear camera: " << moto2.m_cCamera.m_nRear << "\n";
    std::cout << moto << " " << moto2;

    Student student;
    student.PrintData();
    */

    return vExercises;
}

void Menu(std::vector<std::shared_ptr<IExercise>> vExercises)
{

    ///
    /// Menu to choose from the vExercises' emplaced objects
    ///
    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "\n___________________________<MENU>____________________________\n\n"
                     "0.Loops       5.ATM\n"
                     "1.Person      6.Read from File\n"
                     "2.Arrays      7.Write to file\n"
                     "3.Functions   8.Exceptions\n"
                     "4 Structs\n"
                     "\n--------------Standard Template Library---------------------\n\n"
                     "9.Array               18.Set\n"
                     "10.Vector             19.Unordered Set\n"
                     "11.Map                20.Multi Set\n"
                     "12.List               21.Template functions\n"
                     "13.Stack              22.Template class\n"
                     "14.Queue              23.Map in Map\n"
                     "15.Priority Queues    24.Nested Lists\n"
                     "16.Multi Map          25.Nested Vectors\n"
                     "17.Unordered Map      26.Budget Agario\n"
                     "\n___________________________</MENU>____________________________\nSelect Page: ";
        std::cout<<"hello";
        std::cout<<"\33[2K\r";
        uint32_t index = 0;
        std::cin >> index;
        std::cin.ignore(1);

        if (index < vExercises.size())
        {
            vExercises.at(index)->RunExercise();
        }
        else
        {
            std::cout << "Invalid input\n";
            isRunning = false;
        }
    }
}




int main()
{

    Menu(FillExercises());

    return 0;
}
