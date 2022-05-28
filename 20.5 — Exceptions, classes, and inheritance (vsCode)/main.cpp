#include <iostream>
#include <cassert>

template<typename T>
class Array
{
private:
    T m_length{};
    T* m_data{};

public:
    Array(T length)
    {
        assert(length > 0);
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
    assert(index > 0 && index < getLength());
    return m_data[index];
}



int main()
{
    //Exceptions and member functions:
    Array intArray{ 120 };

    for(int count{ 0 }; count < 120; ++count)
    {
        intArray[count] = count;
    }
/*
    for(int count{ 120 }; count > 0; --count)
    {
        std::cout << intArray[count] << ' ';
    }
    std::cout << std::endl;
*/

//    check our assert why not working ?!?!?!

    return 0;
}