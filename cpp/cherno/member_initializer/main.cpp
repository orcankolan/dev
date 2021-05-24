// There is a functional difference between using and not using initilizers. So you should be using initilizaers with primitive types and with classes.

#include <iostream>

class Example
{
public:
    Example()
    {
        std::cout << "Created Example with no parameters!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Example with " << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_name;
    int m_score;
    Example m_Example;
public:
    Entity()
        : m_name("Unknown"), m_score(10), m_Example(Example(8)) //initializers should be in the same order of members declared
    {
//        m_Example = Example(8); //instead of including in initializer list by this way two instance will be craeted

//        m_name = "Unknown"; //no need for this line with initializer
    }

    Entity(const std::string& name)
        : m_Example(9) // if you do not include this initializer e1 with Orcan will initialize Example with no parameters, since there is a Example m_Example in the private section
    {
        m_name = name;
    }

    const std::string& GetName() const
    {
        return m_name;
    }

    const int& GetScore() const
    {
        return m_score;
    }
} e1("Orcan");

int main()
{
    Entity e0;


//    std::cout << e1.GetName() << std::endl;
//    std::cout << e1.GetScore() << std::endl;
    return 0;
}
