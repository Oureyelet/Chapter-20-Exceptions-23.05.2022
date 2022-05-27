#include <iostream>
#include <string_view>
#include <locale>
#include <cmath> // for sqrt() function

std::string_view name(std::string name)
{
    try
    {
        if(!isupper(name[0]))
        {
            throw "Your name stared lowercase\n";
        }

        std::cout << "Your name is: " << name << '\n';
    }
    catch(const char* ex) // note: no variable name since we don't use it in the catch block below
    {
            std::cout << ex << "I hanged your name to uppercase." << '\n';
            name[0] = std::toupper(name[0]);
            std::cout << name << '\n';

    }
    

    return name;
}



int main()
{
     //Throwing exceptions:
    // throw -1;// throw a literal integer value
   //  throw ENUM_INVALID_INDEX;
  //   throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
 //    throw dX; // throw a double variable that was previously defined
//     throw MyException("Fatal Error"); // Throw an object of class MyException
/*
    //Looking for exceptions:
    try
    {
        std::cout << "yo" << '\n';
        // Statements that may throw exceptions you want to handle go here
        return -1;// here's a trivial throw statement
    }*/

    //Handling exceptions:   START FROM HERE <<<---- again...
  /*  catch(int x)
    {
        // Handle an exception of type int here
        std::cerr << "We caught an int exception with value" << x << '\n';
    }*/

    //Putting throw, try, and catch together:
    //std::cout << dividing(3, 8) << '\n';
    //std::cout << dividing(3, 0) << '\n';

    std::string yourname{};
    std::cout << "Enter your name:";
    std::cin >> yourname;
    name(yourname);

    //Recapping exception handling:

    //Exceptions are handled immediately:

    //A more realistic example:
/*    std::cout << "Enter a number: ";
    double x{};
    std::cin >> x;

    try// Look for exceptions that occur within try block and route to attached catch block(s)
    {
        // If the user entered a negative number, this is an error condition
        if(x < 0.0)
            throw "Can not take sqrt of negative number\n"; // throw exception of type const char*

        // Otherwise, print the answer
        std::cout << "The sqrt of " << x << " is " << std::sqrt(x) << '\n';

    }
    catch(const char* exeption) // catch exceptions of type const char*
    {
        std::cerr << "Error: " << exeption << '\n';
    }
*/
    //What catch blocks typically do:
    

    return 0;
}