#include <iostream>
#include "project1.h"
#include <array>

using namespace std;


int main() {

    Project1 p1;
    int value = 2;
    p1.foo(value);
    std::cout<<"executing project code: value = "<<value<<std::endl;

    return 0;
}