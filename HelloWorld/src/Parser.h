#pragma once

#include <vector>
#include <iostream>
#include "pugixml.hpp"

template <typename T>
using Vector2D = std::vector<std::vector<T>>;



class Parser
{
public:
    Parser();
    ~Parser()=default;
    bool Traverse(pugi::xml_node& lines);
    void CheckXml(const char* source);
    void LoadErrorHandling();
    void LoadDocument();
    void ReadXML();
    void PrintCurrentResults();
    void CalcAllLines();
    void ParsePayTable();
    Vector2D<int> GetWinLines();
private:
    Vector2D<int> m_vPayTable=
    {
        {0, 5,  10,  20,  30}, //a if a.count. return m_vPaytable.[figure][count]
        {0, 35, 40,  50,  60}, //b
        {0, 0,  70,  80,  90}, //c
        {0, 0,  100, 110, 120}, //d
        {0, 0,  130, 140, 150}, //e
        {0, 0,  0,   170, 180} //f
    };
    Vector2D<int> m_vWinLines={};
    Vector2D<char> m_vCurrGame={};
    Vector2D<char> m_vPrsLines={};
    std::vector<char> m_vFigures={};//0-5
    int m_nCountElement = 0;
    char m_cWinElement='#';



};
