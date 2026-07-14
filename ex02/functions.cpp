#include "classes.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>

Base* generate(void) {
    int r = rand();
    Base* basePtr;

    if (r % 3 == 0) {
        basePtr = new A();
    }
    else if (r % 3 == 1) {
        basePtr =new B();
    }
    else {
        basePtr = new C();
    }
    return basePtr;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "The pointed to object, is of type A\n";
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "The pointed to object, is of type B\n";
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "The pointed to object, is of type C\n";
    }
    else {
        std::cout << "The pointed to object, is not of type A, nor B, nor C!\n";
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The referenced object, is of type A\n";
        return ;
    }
    catch (const std::exception& e){
        std::cout << "";
    }
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The referenced object, is of type B\n";
        return ;
    }
    catch (const std::exception& e){
        std::cout << "";
    }
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The referenced object, is of type C\n";
        return ;
    }
    catch (const std::exception& e){
        std::cout << "";
    }

    std::cout << "The referenced object, is not of type A, nor B, nor C!\n";
}
