#include <iostream>
#include <cmath> // for sqrt() function

// A modular square root function
double  mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if(x < 0.0)
        throw "Can not take sqrt of negative number";// throw exception of type const char*

    return sqrt(x);
}

int main()
{
    std::cout << "Witam rodzine Szczesniakow\n";

    int x = (1,024);

    std::cout << x << '\n';

    //Uncaught exceptions:

    std::cout << "Enter a number:";
    double y{};
    //std::cin >> y;

    // Look ma, no exception handler!
    std::cout << "The sqrt of " << y << " is " << mySqrt(y) << '\n'; 

    //Catch-all handlers:
    try
    {
        throw 5; // throw an int exception
    }
    catch(double x1)
    {
        std::cerr << "We caught an exception of type double: " << x1 << '\n';
    }
    catch(...)// catch-all handler
    {
        std::cerr << "We caught an exception of an undetermined type\n";
    }
    
    //Using the catch-all handler to wrap main():
    

    return 0;
}