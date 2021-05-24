#include <iostream>
//#include <string>

void PrintString (const std::string& s)
{
//    s += "O";
    std::cout << s << std::endl;
}

int main()
{
    const char* name = "Çamlı"; // although it is a pointer it is not heap allocated, so it doesnt need to be deleted with delete[], if you dont use new keyword on the right hand side, no delete required

//    name[1] = 'e'; //not valid for const char*

    char name2[6] = {'C', 'a', 'm', 'l', 'i', 0}; //valid but you cant use 'Ç' since it will be multi character in a single char

    std::string name3 = std::string("Çamlı") + "güney"; //no need to include <string>

    bool contains = name3.find("lı") != std::string::npos;
//    std::cout << "size: " << name3.size() << std::endl;

//    PrintString(name); //valid if PrintString variable is const
//    PrintString(name2); //valid if PrintString variable is const
    PrintString(name3); //valid


    std::cout << "conatins lı: " << contains << std::endl;
    return 0;
}
