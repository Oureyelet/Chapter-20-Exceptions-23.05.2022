#include <iostream>

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
    catch(int x)
    {
        // Handle an exception of type int here
        std::cerr << "We caught an int exception with value" << x << '\n';
    }

    return 0;
}