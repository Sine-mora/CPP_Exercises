#pragma once

#include <iostream>

class Task1
{
public:
    Task1();
    ~Task1() = default;
    bool Verify();
    void TakeInput(char flagNum1, char flagNum2);
    void PrintN();              // Task 1
    void PrintAB();             // Task 2
    void PrintABx();            // Task 3
    void ShowPrice(short flag); // Task 4,5,6
    void SumAB();               // Task 7
    void MultiplyAB();          // Task 8
    void CalcSquareAB();        // Task 9
    void SumN();                // Task 10
    void Sum2N();               // Task 11
    void MultiplicationN();     // Task 12
    void SumSignChange();       // Task 13
    void PowerOfAN();           // Task 14
    void SubtractFromAB();      // Task 15  //Tasks 16,17,18 Invalid
    void CheckForPower();       // Task 19
    void FindBiggestNum();      // Task 20
    void FindSmallestNum();     // Task 21
    void Bank();                // Task 22
    void Skier();                // Task 23

    /**
     * @brief CompareFloat - Compares two floats using an epsilon value.
     * @param a - first float to be compared.
     * @param b - second float to be compared.
     * @param epsilon - comparison threshold.
     */
    bool AreFloatsEqual(float a, float b, float epsilon = 0.001);

private:
    int m_nNumA = 0, m_nNumB = 0; // N>0
    unsigned int m_unNum1 = 0, m_unNum2 = 0;
    double m_dNum1 = 0, m_dNum2 = 0, m_dTotal = 0;
};
