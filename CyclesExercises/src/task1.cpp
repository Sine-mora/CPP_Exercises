#include <cmath>

#include "task1.h"
#include <cmath>
#include <iostream>
#include <string>

Task1::Task1()
{

    std::cout << "\nTask1:\n";
}

bool Task1::Verify()
{
    if (m_nNumA >= m_nNumB)
    {
        std::cout << "\nA must be lower than B \n";
        return false;
    }
    return true;
}

void Task1::TakeInput(char flagNum1, char flagNum2)
{
    std::string strTempValue = "";

    // Insert Number 1****************************//
    if (flagNum1 == 'i')
    {
        std::cin >> m_nNumA;
    }
    else if (flagNum1 == 'u')
    {
        std::getline(std::cin, strTempValue);
        //        m_unNum1 = std::stoi(strTempValue);
    }
    else if (flagNum1 == 'd')
    {
        std::getline(std::cin, strTempValue);
        m_dNum1 = std::stoi(strTempValue);
    }

    // Insert Number 2*****************************//
    std::cout << "\nInsert B: ";
    if (flagNum2 == 'i')
    {
        std::cin >> m_nNumB;
    }
    else if (flagNum2 == 'u')
    {
        std::getline(std::cin, strTempValue);
        //       m_unNum2 = std::stoi(strTempValue);
    }
    else if (flagNum2 == 'd')
    {
        std::getline(std::cin, strTempValue);
        m_dNum2 = std::stoi(strTempValue);
    }
}

void Task1::PrintN()
{
    std::cout << "Insert times to iterate: ";
    TakeInput('i', 'i');

    for (int itr = 0; itr < m_nNumA; itr++)
    {
        std::cout << "\nNumber 2: " << m_nNumB;
    }
    std::cout << std::endl;
}

void Task1::PrintAB()
{
    std::cout << "Insert starting number and last number [A-B]: ";

    TakeInput('i', 'i');

    std::cout << "\nNumbers being in between: ";
    for (int itr = m_nNumA; itr <= m_nNumB; itr++)
    {
        m_dTotal++;
        std::cout << itr << " ";
    }
    std::cout << "\n\nTotal numbers: " << m_dTotal << "\n";
}

// Task 3
void Task1::PrintABx()
{
    std::cout << "Insert number: ";
    TakeInput('i', 'i');

    for (int itr = m_nNumA + 1; itr < m_nNumB; itr++)
    {
        m_dTotal++;
        std::cout << itr << " ";
    }
    std::cout << "\n Total: " << m_dTotal << std::endl;
}

// Task 4
void Task1::ShowPrice(short int flag)
{
    // unsigned int price = 0;
    // double kilos = 0;

    std::cout << "\nInsert price for 1kg candy: ";
    TakeInput('u', 'd');

    // std::cin >> price;
    // std::cout << "\nHow many kilos? ";
    // std::cin >> kilos;

    switch (flag)
    {
    case 4:
        std::cout << m_unNum1 * (static_cast<unsigned int>(m_dNum2)) << std::endl;
        break;
    case 5:
        std::cout << m_unNum1 * m_dNum2 << std::endl;
        break;
    case 6:
        std::cout << m_unNum1 * m_dNum2 << std::endl;
        break;
    }
}

void Task1::SumAB()
{
    std::cout << "\nSUM !A-B\nInsert A (A<B): ";
    TakeInput('i', 'i');
    if (!Verify())
        return;

    std::cout << "\n Numbers being added: ";
    for (int itr = m_nNumA; itr <= m_nNumB; itr++)
    {
        m_dTotal += itr;
        std::cout << itr << " ";
    }
    std::cout << "\nTotal sum of the numbers A to B: " << m_dTotal << "\n";
    m_dTotal = 0;
}

void Task1::MultiplyAB()
{
    std::cout << "\n Multiply all numbers from A to B (A<B).\n";
    std::cout << "Insert A: ";
    TakeInput('i', 'i');
    if (!Verify())
        return;

    m_dTotal = 1;
    std::cout << "\n Numbers being Multiplied: ";
    for (int itr = m_nNumA; itr <= m_nNumB; itr++)
    {

        m_dTotal *= itr;
        std::cout << itr << " ";
    }
    std::cout << "\nTotal multiplication of the numbers A to B: " << m_dTotal << "\n";
}

void Task1::CalcSquareAB()
{
    std::cout << "\n Find the square of all numbers from A to B (A<B).\n";
    std::cout << "Insert A: ";
    TakeInput('i', 'i');
    if (!Verify())
        return;

    std::cout << "\n Numbers in the line: ";
    for (int itr = m_nNumA; itr <= m_nNumB; itr++)
    {
        std::cout << itr << " ^2= " << itr * itr << " , ";
    }
    std::cout << "\n";
}

// Task 10
void Task1::SumN()
{
    m_dTotal = 0;
    std::cout << "\n Find the sum of 1+ 1/2 +1/3 ... 1/N (N>0)(real numbers).\n";
    std::cout << "Insert N: ";
    std::cin >> m_nNumA;
    // TODO verification
    std::cout << "1/N = ";
    m_dNum1 = 1;
    for (int itr = 1; itr <= m_nNumA; itr++)
    {
        m_dTotal += m_dNum1 / itr;
        std::cout << m_dNum1 << "/" << itr << " ; ";
    }
    std::cout << "Total: " << m_dTotal << "\n";
}

// Task 11
void Task1::Sum2N()
{
    m_dTotal = 0;
    std::cout << "\n Find the sum of 2+(N+1..N+N) (N>0).\n";
    std::cout << "Insert N: ";
    std::cin >> m_nNumA;
    // TODO verification
    std::cout << "2+(" << m_nNumA << "+(1 to " << m_nNumA << ")). \n";
    for (int itr = 1; itr <= m_nNumA; itr++)
    {
        m_nNumB = 2;
        m_dNum2 = m_nNumB + (m_nNumA + itr);
        std::cout << m_nNumB << " + (" << m_nNumA << "+" << itr << ") = " << m_dNum2
                  << "\n";
        m_dTotal = m_dTotal + m_dNum2;
    }
    std::cout << "\nTotal: " << m_dTotal << "\n";
}

// Task 12
void Task1::MultiplicationN()
{
    std::cout << "\n Find the multiplication of 1.1*1.2*1.3 .. (N>0).\n";
    std::cout << "Insert N: ";
    std::cin >> m_nNumA;
    // TODO verification
    std::cout << "Results:\n";
    m_dTotal = 1;
    m_dNum1 = m_nNumA * 10;
    m_nNumB = 1;
    for (double itr = 10; itr <= m_dNum1; itr += 10)
    {
        m_dNum2 = m_nNumB + itr / 100;
        std::cout << m_dNum2 << " ";
        m_dTotal = m_dTotal * m_dNum2;
    }
    std::cout << "\nTotal: " << m_dTotal << "\n";
}

// Task 13 Broken, TODO:
void Task1::SumSignChange()
{
    std::cout << "\n Find the multiplication of 1.1-1.2+1.3- .. (N>0).\n";
    std::cout << "Insert N: ";
    std::cin >> m_nNumA;
    // TODO verification
    std::cout << "Results:\n";
    m_dTotal = 0;
    m_nNumB = 1;
    for (int itr = 1; itr <= m_nNumA; itr += 1)
    {

        m_dNum2 = m_nNumB + (itr / 10.0);
        std::cout << " m_dNum2: " << m_dNum2 << " ";

        if (itr % 2 == 0)
        {
            std::cout << " is even";
            m_dTotal = m_dTotal - m_dNum2;
        }
        else
        {
            m_dTotal = m_dTotal + m_dNum2;
            std::cout << " is odd O.o";
        }
        std::cout << ", m_dTotal: " << m_dTotal << "\n";
    }
    std::cout << "\nTotal: " << m_dTotal << "\n";
}

// Task 14
void Task1::PowerOfAN()
{
    // TODO Verification
    std::cout << "\nPrint all Powers of A.";
    std::cout << "\nInsert number A: ";
    std::cin >> m_dNum1;
    std::cout << "\nInsert maximum power (not less than 1): ";
    std::cin >> m_nNumA;

    for (int itr = 1; itr <= m_nNumA; itr++)
    {
        std::cout << "Power to = " << std::pow(m_dNum1, itr) << "\n";
    }
    std::cout << "\n";
}

// Task 15
void Task1::SubtractFromAB()
{
    std::cout << "Insert 2 numbers A<B\n";
    std::cout << "Insert A: ";
    std::cin >> m_unNum1;
    std::cout << "Inserrt B: ";
    std::cin >> m_unNum2;

    for (unsigned int itr1 = m_unNum1; itr1 <= m_unNum2; itr1++)
    {
        std::cout << "\nNumber iterator 1 : " << itr1 << "\n\t\tMany times: ";
        for (unsigned int itr2 = 1; itr2 <= itr1; itr2++)
        {
            std::cout << itr1 << " ; ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Task 16 Invalid. Repeating Task 8

// Task 17 Invalid. Repeating Task 9

// Task 18 Invalid. Repeating Task 10

// Task 19
void Task1::CheckForPower()
{
    std::cout << "If equal to the power on base 3 (A>0).\n";
    std::cout << "Insert A:";
    std::cin >> m_nNumA; // the result

    m_nNumB = 3; // base
    int nNum3 = m_nNumA % 3;

    if (nNum3 == 0)
    {
        std::cout << "\nTrue. ' " << m_nNumA << " ' is the result 3 on Power\n";
    }
    else if (m_nNumA == 1)
    {
        std::cout << " 1 is the result of 3^0\n";
    }
    else
    {
        std::cout << "False. No power on base of 3 is equal to " << m_nNumA << "\n";
    }
}

// Task 20
void Task1::FindBiggestNum()
{
    std::cout << "\n Find the biggest number (N>0).\n";
    std::cout << "Insert A: ";
    std::cin >> m_nNumA;
    int k = 1;
    while (k * k <= m_nNumA)
    {
        k++;
    }
    std::cout << "Max K: " << k << "\n";
}

// Task 21
void Task1::FindSmallestNum()
{
    std::cout << "\n  Find smallest number for it being (3^K) > N (N>1)\n";
    std::cout << "Insert A: ";
    std::cin >> m_nNumA;

    int k = 0;
    while (std::pow(3, k) <= m_nNumA)
    {
        k++;
    }
    std::cout << "Min K: " << k << "\n";
}

// Task 22
void Task1::Bank()
{
    std::cout << "Bank\n";
    std::cout << "Insert interest (0<P<25)%\n";
    std::cin >> m_dNum1; // interest Percentage
    double rate = m_dNum1;
    double interest = 0;
    int deposit = 100;
    double result = deposit;
    int months = 0;
    while (result <= 1100)
    {
        interest = (result * rate) / 100;
        months++;
        result += interest;
        std::cout << "( result: " << result << "* Rate: " << rate
                  << ")/100 = " << interest << " Interest: "
                  << "\n";
    }
    std::cout << "Deposit: " << deposit << " with rate of " << rate << "% .\n";
    std::cout << "It will take " << months
              << " months in order to exceed 1100 with total of " << result << "\n";
}

// Task 23
void Task1::Skier()
{
    std::cout << "\nSkier's training:\n";
    std::cout << "(0<P<50)%\n";
    std::cin >> m_dNum1;
    double rate = m_dNum1;
    double dDayRun = 10.0;  //km
    int nMaxKM = 200;       //km
    double dTotalRun = 0;   //km
    int nDays = 0;
    double interest = 0;
    while (dTotalRun < nMaxKM)
    {
        interest = (dDayRun * rate) / 100;
        dDayRun = dDayRun + interest;
        dTotalRun = dTotalRun + dDayRun;
        nDays++;
        std::cout << " dDayRun: " << dDayRun << ", dTotalRun: " << dTotalRun << " \n";
        if(nDays > 20) break;
    }
    std::cout << "\n in " << nDays << " days, he ran: " << dTotalRun << "\n";
}

bool Task1::AreFloatsEqual(float a, float b, float epsilon)
{
    // |a-b| <= epsilon, true
    float fResult = std::fabs(static_cast<float>(a - b));
    bool isEqual = (fResult < epsilon);
    //    std::cout << " a: " << a << ", b: " << b << ", epsilon: " << epsilon
    //              << ", fResult: " << fResult << ", isEqual: " << isEqual << "\n";
    return isEqual;
}
