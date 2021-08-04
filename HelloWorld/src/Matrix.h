#pragma once
#include <iostream>
#include <vector>

class Matrix{
public:
    Matrix(int nRows, int nColumns,
           int iWinLines, int iFigures);
    void Fill();
    void WinLine();
    void GameLost();
    void SetMatrix(int w, int h);
    void SetWinLines(std::vector<std::vector<int>> vSet);
    void ShowMatrix();
    int  GetWinLine();
private:
    std::vector<std::vector<int>> m_vMatrix{};
    std::vector<std::vector<int>> m_vFigures{};
    std::vector<std::vector<int>> m_vCurrCycle{};
    int m_iFigures=5;
    int m_iWinningLines = 5;
};
