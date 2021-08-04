#pragma once

#include <iostream>

class Base
{
public:
    Base();
    virtual ~Base();
    virtual void F();    //Без virtual се изпълняват само те, но не и тези, които са имплементирани в наследника.
};
