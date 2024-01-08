#include <iostream>
#include <string>

class MyClass
{
    public:
    std::string constructorMessage = "Object constructed";
    std::string destructorMessage = "Object destructed";

    MyClass()
    {
        std::cout << constructorMessage << std::endl;
    }
    MyClass(std::string message)
    {
        std::cout << constructorMessage << " with overloaded constructor. Argument is: " << message << std::endl;
    }

    ~MyClass()
    {
        std::cout << destructorMessage << std::endl;
    }
};

int main(){
    MyClass *firstObject = new MyClass;
    MyClass *secondObject = new MyClass("passed this string as an argument");
    std::cout<<"Addresses of the objects are "<<&(*firstObject)<<" and "<< &(*secondObject)<<std::endl;

    delete firstObject;
    delete secondObject;
    

    return 0;
}