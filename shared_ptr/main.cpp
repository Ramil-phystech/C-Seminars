#include <iostream>
#include "pointer.h"

class A {
public:
    int a = 0;
    int b = 0;

    A(int a_, int b_) {
        a = a_;
        b = b_;
    }

    A(const A &rhs) {
        a = rhs.a;
        b = rhs.b;
    }

    void Meow() {
        std::cout << "Meow" << std::endl;
    }
};

int main() {
    A a2 = A(2, 3);
    Shared_ptr<A> p = a2;
    Shared_ptr<A> q = p;

    std::cout << q->a << std::endl;
    std::cout << p->b << std::endl;

    q->Meow();

    std::cout << (*q).a << std::endl;

    return 0;
}
