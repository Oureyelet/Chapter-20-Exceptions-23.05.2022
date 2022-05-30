#include <iostream>
#include <cassert>
#include <string>
#include <string_view>

template<typename T>
class Array
{
private:
    T m_length{};
    T* m_data{};

public:
    Array(T length)
    {
        //assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    ~Array()
    {
        delete[] m_data;
    }

    const T& getLength() const { return m_length; }

    T& operator[](const T index);
};

template<typename T>
T& Array<T>::operator[](const T index)
{
   // assert(index >= 0 && index <= getLength()); // how we read this: if index will be greather then 0 is good ! 

    if(index < 0 || index > getLength())
        throw index;

    return m_data[index];
}

class Member
{
public:
    Member()
    {
        std::cerr << "Member allocated some resources\n";
    }

    ~Member()
    {
        std::cerr << "Member cleaned up\n";
    }
};

class A
{
private:
    int m_x{};
    Member member;

public:
    A(int x)
        :m_x{ x }
    {
        if(x <= 0)
            throw -1;
    }

    ~A()
    {
        std::cerr << "~A\n";// should not be called
    }
};

class ArrayException
{
private:
    std::string m_error{};

public:
    ArrayException(std::string error)
        : m_error{ error }
    {
    }

    std::string_view getError() const { return m_error; }

};




template<typename T>
class IntArray
{
private:
    T m_data[3]{};// assume array is length 3 for simplicity

public:
    IntArray() = default;

    T getLength() const { return 3; }

    T& operator[](const T index)
    {
        if(index < 0 || index >= getLength())
            throw ArrayException{ "Invalid index" };
        return m_data[index];
    }

};

class Base
{
public:
    Base(){}
};

class Derived: public Base
{
public:
    Derived(){}
};

int main()
{
    //Exceptions and member functions:
    Array my_intArray{ 120 };

    for(int count{ 0 }; count < 121; ++count)
    {
        my_intArray[count] = count;
    }

    for(int count{ 120 }; count > 0; --count)
    {
        std::cout << my_intArray[count] << ' ';
    }
    std::cout << std::endl;

    //When constructors fail:
    
    try
    {
        A a{ 0 };
    }
    catch(int)
    {
        std::cerr << "Oops\n" << '\n';
    }
    
    //Exception classes:
    IntArray<int> array;

    try
    {
        int value{ array[5] }; // out of range subscript
    }
    catch(const ArrayException& exeption)
    {
        std::cerr << "An array exception occurred (" << exeption.getError() << ")\n";
    }
    
    //Exceptions and inheritance:
    try
    {
        throw Derived();
    }
    catch(const Derived& derived)
    {
        std::cerr << "caught derived" << '\n';
    }
    catch(const Base& base)
    {
        std::cerr << "caught derived" << '\n';
    }
    
    //std::exception:
    



    return 0;
}