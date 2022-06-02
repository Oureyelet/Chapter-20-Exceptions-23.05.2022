#include <iostream>

class A
{
private:
    int m_x{};

public:
    A(int x)
        :m_x{ x }
    {
        
    }
};

class B: public A
{
public:
    B(int x) try // note addition of try keyword here
        : A{ x }
    {
        if(x <= 0) // moved this from A to B
            throw 1; // and this too, and output will be same as this exeptions was inside A constructor
    }
    catch(...) // note this is at same level of indentation as the function itself
    {
        // Exceptions from member initializer list or constructor body are caught here

        std::cerr << "Exeption caught\n";

        // If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
    }
};

int main()
{
    
    //Function try blocks:
    try
    {
        B b{ 0 };
    }
    catch(int)
    {
        std::cout << "Oops" << '\n';
    }

    //Function try blocks can catch both base and the current class exceptions:

    //Don’t use function try to clean up resources:
    

    


    return 0;
}