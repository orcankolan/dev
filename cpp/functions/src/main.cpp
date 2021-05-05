#include <iostream>

double Multiply(int a, int b) { return a * b; }
/*  Functions can return any data type also Void(return nothing) */

void myMultiply(int a, int b) {
    std::cout << "Result is: " << a * b << std::endl;
}

int main() {
    std::cout << "Result: " << Multiply(4, 56) << std::endl;
    std::cout << "Result: " << Multiply(4, 32) << std::endl;

    myMultiply(5, 12);
    /*  All functions except main has to return the specified data type
        (only in debug mode, in release mode compiler gives no error)
        main() return 0 if it is succesful.

        Generally function declarations are kept in the header files
        Definitions are kept in the cpp (transilation units) files
     */

    return 0; // not neccessary line
}
