#include "exercise2.h"

Exercise2::Exercise2()
{
}

bool Exercise2::CompareFloats(float num1, float num2)
{
    const float epsilon = 0.005;

    return std::abs(num1 - num2) <= epsilon * std::abs(num1);
}

void PrintAsterisk(int nCurrRow, int nCurrCol, int nRows, int nCols)
{
    int nMidRow = nRows / 2;
    int nStartRow = nMidRow - nCurrCol;
    int nEndRow = nRows - nCurrCol;
    if ((nStartRow < nEndRow) && (nCurrRow >= nStartRow) && (nCurrRow <= nEndRow))
    {
        std::cout << "*";
    }
    else
    {
        std::cout << " ";
    }
    if (nCurrCol == nCols - 1)
    {
        std::cout << "\n";
    }
}

void Exercise2::PrintTriangle()
{
    /*int nRows = 7;
    int nCols = 6;
    for (int nCurrRow = 0; nCurrRow < nRows; nCurrRow++)
    {
        for (int nCurrCol = 0; nCurrCol < nCols; nCurrCol++)
        {
            PrintAsterisk(nCurrRow, nCurrCol, nRows, nCols);
        }
    }*/

    // ____*____
    // ___*_*___
    // __*___*__
    // _*_____*_
    // *___*___*

    // ___*
    // __***
    // _*****

    // *
    // ***
    // *****
    // ****
    // ***
    // *

    // variant 1
    //    int value = 3;
    //    int space = value;
    //    for (int i = 0; i < value; i++)
    //    {
    //        for (int j = space; j > 0; j--)
    //        {
    //            std::cout << "_";
    //        }
    //        for (int star = 0; star <= i * 2; star++)
    //        {
    //            std::cout << "*";
    //        }
    //        space--;
    //        std::cout << std::endl;
    //    }
    //    std::cout << std::endl;

    //    // variant 2
    //    for (int itr1 = 0; itr1 < 5; itr1++)
    //    {
    //        // int count=0;
    //        for (int itr2 = 0; itr2 < 3; itr2++)
    //        {

    //            if (itr1 == itr2)
    //            {
    //                std::cout << itr1 << "-" << itr2 << "*";
    //            }
    //        }

    //        std::cout << std::endl;
    //    }

    //    // variant 3
    //    std::cout << "\nVariant 3\n";
    //    int itr1 = 1, n=3, k=0;
    //    while ( k< (n - itr1 - 1) )
    //    {
    //        std::cout << "\nWhile 3\n";
    //        for (int itr2 = 1; itr2 <= 3; itr2++)
    //        {

    //            if (itr1 == itr2)
    //            {
    //                std::cout << "*";

    //                if (itr2 == (4 - 1))
    //                {
    //                    itr1--;
    //                }
    //                else
    //                {
    //                    itr1++;
    //                }
    //            }
    //        }
    //        std::cout << std::endl;
    //    }
    // int half = 5;

    // *
    // **
    // ***
    // **
    // *
    /*  {
     * //С един цикъл
     *
          int nMaxRows = 10;
          int nHalfRows = nMaxRows / 2;
          for (int i = 0; i < nMaxRows ; i++)
          {
              // std::cout << i << "_";

              int temp = i;
              if (i >= nHalfRows)
              {
                  temp = temp - (i%nHalfRows)*2;

              }
  //            std::cout<<temp<<"\n";
              for (int j = 0; j < temp; j++)
              {
                  std::cout << "*";
              }

              std::cout << "\n";
          }
          else
                  {

                      for (int j = i - nHalfRows + 1; j < nHalfRows; j++)
                      {
                          std::cout << "*";
                      }
                      std::cout << "\n";
                  }
      }
      std::cout << "\n";
  }*/

    //   *
    //  **
    // ***
    //  **
    //   *
    /*
        int nMaxRows = 10;
        int nHalfrows = nMaxRows / 2;
        for (int i = 0; i < nMaxRows - 1; i++)
        {
            std::cout<<"-"<<i<<"\n";
            if (i < nHalfrows)
            {
                for (int j = nMaxRows-i; j<=0;j++)
                {
                    std::cout<<"_";
                }
                std::cout<<"~\n";
            }else{
                std::cout<<"Else\n";
            }

        }*/

    //    int nRowMax=7;
    //    int nColumnMax=6;
    //    for(int i=0; i<nRowMax; i++)
    //    {
    //        for(int j=0; j<nColumnMax; j++)
    //        {
    //            if( (j == i) && () )

    //            }

    //        }

    //    }

    /*
    int nRowMax = 7;
    int nColumnMax = 6;
    int nHalfRow = nRowMax / 2;
    int nHalfColumn = nColumnMax / 2;
    int mark = 0;

    for (int i=0; i<nRowMax;i++)
    {
        for (int j=0;j<nColumnMax;j++)
        {
            mark=i+(j+1);
            std::cout<<"Rows: * Columns:";
            while( (mark <= nHalfRow) && (mark <= nHalfColumn) )
            {
                std::cout<<i<<" * "<<j<<" ";
            }
            std::cout<<"\n";
        }
    }*/
}

void Exercise2::PrintRing()
{
    //TODO
}
