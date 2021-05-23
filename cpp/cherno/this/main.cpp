#include <iostream>
#include <string>

class Entity
{
private:
    int x,y;
    void printEntity(const Entity&);

public:
    Entity(int x, int y)
    {
        this->x = x;
        (*this).y = y;

        printEntity(*this); // u have to dereference to be able to use with reference in the above declared function
    }

    int GetX() const
    {
//        const Entity* const e = this;
//        return e->x;
        return this->x; //same as above 2 lines
    }

};


void Entity::printEntity(const Entity& e)
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    Entity e(5,6);

    return 0;
}
