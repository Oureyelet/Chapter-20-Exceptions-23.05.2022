#include <iostream>
#include <exception>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    try
    {
        add(23.2, 9.8);
    }
    catch(const std::exception& e)
    {
        std::cerr << "???" << e.what() << '\n';
    }
    


    return 0;
}