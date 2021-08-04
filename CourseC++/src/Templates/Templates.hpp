#include "Templates.h"

/* Issue: Function Overloading, we have to
 * create separate functions for different data types
 *
 * Expanded at Compile time
 * Generic Programming
 *
 * CLASS TEMPLATE
 *
 * We write a generic class that can be used for different data types.
 */

void TemplateFuncExample::RunExercise()
{
    std::cout << "\n======================================================\n\t\tTemplate "
                 "functions\n";
    int x = 2, y = 5;
    std::cout <<"Template function: "<<Sum(x,y);

    std::cout << "\n======================================================\n";
}

void Sum(int x, int y)
{
    std::cout << "\n Int: " << x + y << "\n";
}

/*
void TemplateExample::Sum(float x, float y)
{
    std::cout << "\n Float: " << x + y << "\n";
}

void TemplateExample::Sum(double x, double y)
{
    std::cout << "\n Double: " << x + y << "\n";
}

void TemplateExample::Sum(const std::string& x, const std::string& y)
{
    std::cout << "\n String: " << x + y << "\n";
}
*/

template <class T>
T TemplateFuncExample::Sum(T x, T y)
{
    return x + y;
}

// CLASS TEMPLATE

template<class T>
void TemplateClassExample<T>::RunExercise()
{
    std::cout << "\n==============================================\n\t\tTemplate Class\n";

    std::cout << " Enter var1: ";
    std::cin >> var1;
    std::cout << " Enter var2: ";
    std::cin >> var2;

    Add();

    std::cout << "\n==============================================\n";
}

template <class T>
void TemplateClassExample<T>::Add()
{
    std::cout << "var1(" << var1 << ") + var2(" << var2 << ") = "
              << (var1 + var2) << "\n";
}
