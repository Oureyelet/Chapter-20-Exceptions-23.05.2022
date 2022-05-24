#include <iostream>
#include <string_view>

double doDivision(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "Error: Could not divide by zero\n";
        std::exit(1);
    }
    return static_cast<double>(x) / y;
}

int findFirstChar(std::string_view string, char ch)
{
    for(std::size_t index{ 0 }; index < string.length(); ++index)// Step through each character in string
        if(string[index] == ch)// If the character matches ch, return its index
            return index;

    return -1;// If no match was found, return -1
}

int main()
{
    std::cout << "Hello World my name is Sophie" << '\n';

    std::cout << doDivision(2, 23) << '\n';

    //When return codes fail: 
    std::cout << findFirstChar("Hello World", 'x') << '\n';

    //Exceptions:
    

    return 0;
}