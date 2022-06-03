#include <iostream>

void doSomething() noexcept // this function is non-throwing
{
    /*code...*/
}

void doSomething_non_throwing() noexcept(true) //meaning the function is non-throwing
{
    /*code...*/
}

void doSomething_potentially_throwing() noexcept(false) //meaning the function is non-throwing or potentially
{
    /*code...*/
}

void foo() { throw -1; }
void boo() {};
void goo() noexcept {};
struct S{};

int main()
{
    //The noexcept specifier:
    doSomething();

    //The noexcept specifier with a Boolean parameter:
    doSomething_non_throwing();
    doSomething_potentially_throwing();

    //Which functions are non-throwing and potentially-throwing:

    //The noexcept operator can be used inside functions:
    constexpr bool b1{ noexcept(5+3) };// true; ints are non-throwing
    constexpr bool b2{ noexcept(foo()) };// false; foo() throws an exception
    constexpr bool b3{ noexcept(boo()) };// false; boo() is implicitly noexcept(false)
    constexpr bool b4{ noexcept(goo()) };// true; goo() is explicitly noexcept(true)
    constexpr bool b5{ noexcept(S{}) };// true; a struct's default constructor is noexcept by default

    //Exception safety guarantees:

    //Why it’s useful to mark functions as non-throwing:

    //Dynamic exception specifications:

    /*
    Before C++11, and until C++17, dynamic exception specifications were used in place of noexcept:

    int doSomething1() throw();// does not throw exceptions
    int doSomething2() throw(std::out_of_range, int*);// may throw either std::out_of_range or a pointer to an integer
    int doSomething3() throw(...);// may throw anything
    */


    return 0;
}