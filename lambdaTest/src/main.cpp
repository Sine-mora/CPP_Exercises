#include <iostream>
#include <functional>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <random>

class Test
{
public:
    void SetFunc(const std::function<void()>& argFunc) { testFunc = argFunc; }
    void ExecuteFunc() { testFunc(); }
private:
    std::function<void()> testFunc{};
};

class TestRand
{
public:
    void ExecuteRand()
    {
          int iSecret, iGuess;

          /* initialize random seed: */
          srand (time(NULL));

          do {
              /* generate secret number between 1 and 10: */
              iSecret = rand() % 10 + 1;
            std::cout <<  "Guess the number (1 to 10): iSecret: " << iSecret << "\n";
            std::cin >> iGuess;
            if (iSecret<iGuess)
            {
                std::cout << "The secret number is lower \n";
            }
            else if (iSecret>iGuess)
            {

                std::cout << "The secret number is higher\n";
            }
          } while (iSecret!=iGuess);

          std::cout << "Congratulations!";
    }

    void ExecuteUniformDistribution()
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 10.0);

        for (int i=0; i<16; ++i)
        {
            std::cout << dist(mt) << "\n";
        }
    }

};

//TODO Implement stack
class Stack
{
public:

private:

};

int main(/*int argc, char *argv[]*/)
{
    Test testObj{};
    {
        int a = 10;
        int& ref = a;
        auto test = [&ref]()
        {
            std::cout << "before a is " << ref << "\n";
            ref += 10;
            std::cout << "after a is " << ref << "\n";
        };
        testObj.SetFunc(test);
    }

    testObj.ExecuteFunc();

    TestRand randTest;
    randTest.ExecuteUniformDistribution();









    return 0;
}
