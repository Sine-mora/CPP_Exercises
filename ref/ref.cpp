#include <iostream>

int main()
{
    int i = 5;
    std::cout << "i is " << i << "\n";
    int& ref = i;
    std::cout << "ref is " << ref << "\n";
    int k = 6;
    std::cout << "k is " << k << "\n";
    ref = k;
    int* ptr = &ref;
    std::cout << "after assigning k to ref, ref is " << ref << " and i " << i << "\n"
    << "address of i: " << &i << ", address of ref: " << &ref
    << ",\n *ptr: " << *ptr << ", ptr: " << ptr << ", &ptr: " << &ptr << ", (ptr+1): " << (ptr+1) << "\n";
    
    
    int* p = &k;
    k = 3;
    std::cout<<"Test "<<*p<<"\n";
    
    return 0;
}
