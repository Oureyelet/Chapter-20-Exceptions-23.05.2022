#include <iostream>
#include <string>
#include <exception> // for std::exception
#include <stdexcept>// for std::runtime_error

class ArrayException: public std::runtime_error
{
private:

public:
    // std::runtime_error takes a const char* null-terminated string.
	// std::string_view may not be null-terminated, so it's not a good choice here.
	// Our ArrayException will take a const std::string& instead,
	// which is guaranteed to be null-terminated, and can be converted to a const char*.
    ArrayException(const std::string& error)
        : std::runtime_error{ error.c_str() }// std::runtime_error will handle the string
    {
    }

    // no need to override what() since we can just use std::runtime_error::what()
};

class IntArray
{
private:
    int m_data[3]{}; // assume array is length 3 for simplicity

public:
    IntArray() = default;

    int getLength() const { return 3; }

    int& operator[](const int index)
    {
        if(index < 0 || index > getLength())
            throw ArrayException("Invalid index");

        return m_data[index];
    }

};

int main()
{
    IntArray array;

    try
    {
        int value{ array[5] };
    }
    catch(const ArrayException& e)// derived catch blocks go first
    {
        std::cerr << "An array exception occurred (" << e.what() << ")\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Some other std::exception occurred (" << e.what() << ")\n";
    }

    return 0;
}