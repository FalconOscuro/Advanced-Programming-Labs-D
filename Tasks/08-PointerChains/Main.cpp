#include<iostream>

int main()
{
    void* a = nullptr;
    void* b = &a;
    void* c = &b;
    void* d = &c;
    a = &d;

    std::cout 
        << "a: "        << a << '\n'
        << "*a: "       << (void*)(*(long int*)a) << '\n'
        << "**a: "      << (void*)(**(long int**)a) << '\n'
        << "***a: "     << (void*)(***(long int***)a) << '\n'
        << "****a: "    << (void*)(****(long int****)a) << std::endl;
    
    void* p = a;
    while (true)
    {
        std::cout << p << std::endl;
        p = (void*)(*(long int*)p);
    }
    
}