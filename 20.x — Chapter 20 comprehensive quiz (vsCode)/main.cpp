#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <exception> // for std::exeption

template<typename T>
class Fraction
{
private:
    T m_numerator = 0;
    T m_denominator = 1;

public:
    Fraction(T num = 0, T den = 1)
        : m_numerator{ num }, m_denominator{ den }
    {
        if(m_denominator == 0)
            throw std::runtime_error("Invalid denominator");
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction<int>& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction<int>& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator << '\n';

    return out;
}

int main()
{

    /*
    Chapter quiz

    Write a Fraction class that has a constructor that takes a numerator and a denominator. If the user passes in a 
    denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). In your main 
    program, ask the user to enter two integers. If the Fraction is valid, print the fraction. If the Fraction is invalid, 
    catch a std::exception, and tell the user that they entered an invalid fraction.

    Here’s what one run of the program should output:

    Enter the numerator: 5
    Enter the denominator: 0
    Invalid denominator
    */

    std::cout << "Enter the numerator: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter the denominator: ";
    int y{};
    std::cin >> y;

    try
    {
        Fraction fraction{x, y};
        std::cout << fraction;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    
    




    return 0;
}