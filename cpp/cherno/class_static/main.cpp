#include <iostream>

class Entity
{
public:
    static int x, y; //one instace of x y for all instances

    static void Print() // static functions cannot access non-static variables. Static methods, unlik non-static ones, dont have instances passed as hidden parameters. Looks like the function out of this class
    {
        std::cout << x << ", " << y << std::endl;
    }
};

//static void Print(Entity e)
//{
//    std::cout << e.e.yx << ", " << y << std::endl;
//}

int Entity::x;
int Entity::y;

int main()
{
    Entity ugur;
//    ugur.x = 2;
//    ugur.y = 3;
    Entity::x = 2;
    Entity::y = 3;

//    Entity orcan = { 5, 8 }; //if you use static you cant initialize orca like this, because since you use static,  x and y are not class members anymore
    Entity orcan;
    orcan.x = 5;
    orcan.y = 8;

    ugur.Print();
    orcan.Print();

    return 0;
}
