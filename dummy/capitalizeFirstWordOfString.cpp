#include <iostream>

using namespace std;

int main(){
    string myString = "Hello world";
    //Can also use "auto" for type
    string::size_type i;
    // i<myString.size() keeps us within bounds of the whole string (in case the string is one long word).
    // !isspace(myString[i]) breaks the iteration when we are done with the first word.
    for(i = 0; i<myString.size() && !isspace(myString[i]); i++){
        //mystring[i] returns a reference to the character at index i in the string. So that reference can be assigned to a capitalized version of that character.
        myString[i] = toupper(myString[i]);
    }

    cout<<"string is now: " << myString << endl;

    return 0;
}