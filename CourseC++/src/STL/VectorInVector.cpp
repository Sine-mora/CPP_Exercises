#include "VectorInVector.h"

void NestedVectors::RunExercise()
{
    std::vector<int> vec1 ={40,50,20};
    std::vector<std::vector<int>> vec2 = {{1,2,3}, {4,5,6}};
    vec2.push_back(vec1);

    /*
    for(std::size_t i =0; i < vec2.size();i++)
    {
        for(std::size_t j =0; j< vec2[i].size();j++)
        {
            std::cout << vec2[i][j];
        }
    }
    */

    for(auto & i : vec2)
    {
        for(int j : i)
        {
            std::cout << j << " ";
        }
        std::cout <<"\n";
    }

    std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> vector5D =
    {
        {
            {
                {
                    {1,2,3} , {4,5,6}
                }
                ,
                {
                    {7,8,9} , {10,11,12}
                }
            }
            ,
            {
                {
                    {13,14,15} , {16,17,18}
                }
                ,
                {
                    {19,20,21} , {22, 23, 24}
                }
            }
        }
        ,
        {
            {
                {
                    {25,26,27} , {28,29,30}
                }
                ,
                {
                    {31,32,33} , {34,35,36}
                }
            }
            ,
            {
                {
                    {37,38,39} , {40,41,42}
                }
                ,
                {
                    {43,44,45} , {46,47,48}
                }
            }
        }
    };


}
