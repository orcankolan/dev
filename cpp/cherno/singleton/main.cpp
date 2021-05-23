#include <iostream>

// A singleton is a single instance of a class. A class that you intend to have only one instance. Useful when you want to have functionality applies to some global data. Almost using a class just like a namespace and use the functions of it.

class Singleton
{
public:
    Singleton(const Singleton&) = delete;

    static Singleton& Get() // function should return some kind of instance (one instance)
    {
        return s_Instance;
    }

    void Function()
    {
        std::cout << "Singleton function" << std::endl;
    }

private:
    Singleton() {} //constructor is private to prevent initiation outside this class

    float m_Data = 0.02f;

    static Singleton s_Instance; // this will be return with the Get function. but since it is static it should be defined somewhere? In some cpp file or like below
};

Singleton Singleton::s_Instance;

int main()
{
//    Singleton instance; // this is not allowd since the constructor is private within the class

//    Singleton instance = Singleton::Get(); // this is allowed by creating a copy. Creating an additional instance with all the memeber data copied. This is a copy constructor. This can be prevented by deleting copy constructor.

    Singleton& instance = Singleton::Get(); // this is valid and not creating a copy.

    instance.Function();
}
