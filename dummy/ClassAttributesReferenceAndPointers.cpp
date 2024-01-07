#include <iostream>
#include <string>

class MyClass
{
public:
    std::string stringAttribute;

    void SetStringAttribute(std::string s)
    {
        stringAttribute = s;
    }

    void writeStringAttribute()
    {
        std::cout << "Attribute: " << stringAttribute << std::endl;
    }
};

int main()
{
    MyClass myClassObject;

    MyClass *ptr = nullptr;
    ptr = &myClassObject;

    ptr->SetStringAttribute("String set through pointer with arrowoperator");
    (*ptr).SetStringAttribute("String set through pointer by dereferencing with asterisk");

    std::cout << "Line 27. Get member variable from pointer with arrowoperator: " << ptr->stringAttribute << std::endl;
    std::cout << "Line 28. Get member variable from object with dot operator: " << myClassObject.stringAttribute << std::endl;

    std::cout << "\nLine 30. Call function from the object with dotoperator: " << std::endl;
    myClassObject.writeStringAttribute();
    std::cout << "\nLine 32. Call function from pointer with arrowoperator: " << std::endl;
    ptr->writeStringAttribute();

    std::cout << "\nLine 35. Make a reference and call the attribute and function from that." << std::endl;
    MyClass &ref = myClassObject;
    std::cout << "Line 37. Member variable from reference: " << ref.stringAttribute << std::endl;
    ref.writeStringAttribute();

    // Testing references only
    int i = 10;
    int &iRef = i;

    std::cout << "Int i is: " << i << " and iRef is: " << iRef << " and after incrementing from reference: "<<++iRef<< std::endl;

    return 0;
}
