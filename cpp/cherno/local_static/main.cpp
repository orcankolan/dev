#include <iostream>

//int i = 0; // this is same as the static int in the fuction, but can be reached from everywhere

void Function()
{
    static int i = 0; //try without static keyword. With static its lifetime becomes global but cannot reached out of the scope.
    i++;
    std::cout << i << std::endl;
}

int main()
{
    Function();
    Function();
//    i = 10;   //try this with gloval int
    Function();
    Function();
    Function();
}
