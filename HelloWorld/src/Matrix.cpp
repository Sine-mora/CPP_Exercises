#include "Matrix.h"

Matrix::Matrix(int nRows, int nColumns,
               int iWinLines, int iFigures)
{
    m_iWinningLines = iWinLines;
    m_iFigures = iFigures;

    SetMatrix(nRows, nColumns);
}

void Matrix::Fill()
{

}

void Matrix::WinLine()
{
    std::cout<<"Winning Line: "/**/;
}

void Matrix::GameLost()
{
    std::cout<<"Better Luck Next Time\n";
}

void Matrix::SetWinLines(std::vector<std::vector<int>>)
{

}

void Matrix::SetMatrix(int nRows, int nColumns)
{
    //TODO Random Numbers
    m_vMatrix.clear();

    for(int i = 0; i < nRows; i++)
    {
        std::vector<int> vTemp;
        for(int j = 0; j < nColumns; j++)
        {
            vTemp.push_back(i);
        }
        m_vMatrix.push_back(vTemp);
    }

}

void Matrix::ShowMatrix()
{
    for(std::size_t i = 0; i<m_vMatrix.size(); i++)
    {
        for(std::size_t j = 0; j < m_vMatrix.at(i).size(); j++)
        {
            std::cout<<m_vMatrix.at(i).at(j);
        }
        std::cout<<std::endl;
    }
}

int Matrix::GetWinLine()
{
    //TODO
    int id = 0;

    return id;//m_vCurrCycle;
}
