#include <iostream> // for std::cout, std::cin
#include <string> // for std::string
#include <memory> // for std::unique_ptr
#include <string_view> // for std:;string_view
#include <cstddef> // for std::size_t


enum class Sex
{
    PERSON_MALE,
    PERSON_FEMALE
};


class Person
{
private:
    std::string m_name{};
    int m_age{};
    Sex m_sex;

public:
    Person(std::string_view name, int age, Sex& sex)
        : m_name{ name }, m_age{ age }, m_sex{ sex }
    {
    }

    std::size_t getNameLength() const { return m_name.length(); }
    int getAge() const { return m_age; }
    void getInfo()
    {
        std::cout << m_name << " has " << m_age << '\n';
    }

};

Person processPerson(Person& person)
{
    if(person.getNameLength() < 2 || person.getAge() < 18)
        throw 1;

    person.getInfo();
  
    return person;    
}



int main()
{
    std::cout << "Hello World" << '\n';

    //Cleaning up resources:
    Sex PERSON_MALE{ Sex::PERSON_MALE };
    
    Person* john{ nullptr };
    
    try
    {
        john = { new Person("John", 18, PERSON_MALE) };
        processPerson(*john);
        delete john;

    }
    catch(int)
    {
        delete john;
        std::cerr << "Person details failed.\n";
    }
    


    return 0;
}