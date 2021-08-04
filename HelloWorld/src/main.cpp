#include <iostream>
#include "Mathematics.h"
#include "Animal.h"
#include "Matrix.h"
#include "pugixml.hpp"
#include "Parser.h"

#include <cstring>

void func(char* array)
{
    int idx = 0;
    while (array[idx] != '\0')
    {
        std::cout<< (int) array[idx] << " ";
        idx++;
    }
}

int main()
{

    Animal cat;
    cat.Speak();

    Matrix mat(1,2,3,4);
    mat.SetMatrix(3,5);
    mat.ShowMatrix();

    Parser parser;
    std::cout<<std::endl;
    parser.ReadXML();
    parser.CalcAllLines();
    parser.PrintCurrentResults();
    parser.ParsePayTable();

    std::cout <<"\n"<< add(10, 10) << std::endl;
    std::cout<<"Hello world"<<std::endl;

    char emo[20] = "programmer";
    func(emo);



    return 0;
}
