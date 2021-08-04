#include <iostream>
#include <functional>

class Test
{
public:
    void SetFunc(const std::function<void()>& argFunc) { testFunc = argFunc; }
    void ExecuteFunc() { testFunc(); }
private:
    std::function<void()> testFunc{};
};

int main(int argc, char *argv[])
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

    return 0;
}
