#include <iostream>

class Base
{
public:
    Base() = default;

    virtual void print() { std::cout << "Base\n";  }
};

class Derived: public Base
{
public:
    Derived() = default;

    void print() override { std::cout << "Derived\n"; }
};


int main()
{
    std::cout << "Hello Rober bracie kochany :)" << '\n';

    //Rethrowing an exception (the right way):
    try
    {
        try
        {
            throw Derived{};
        }
        catch(Base& b)
        {
            std::cout << "Caught Base b, which is actually a ";
            b.print();
            throw;// note: We're now rethrowing the object here
        }
        
    }
    catch(Base& b)
    {
        std::cout << "Caught Base b, which is actually a ";
        b.print();
    }

    return 0;
}