#include "classes.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    class zzz : public Base{};
    zzz* z = new zzz();
    srand(time(0));

    Base *bA = new A();
    Base *bB = new B();
    Base *bC = new C();

    identify(bC);
    identify(bB);
    identify(bA);
    identify(z);

    identify(*bC);
    identify(*bB);
    identify(*bA);
    identify(*z);
}
