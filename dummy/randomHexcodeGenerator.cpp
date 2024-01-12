#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> rs{5,"R"};

    for(string r: rs){
        cout << r <<endl;
    }


    const string hexadecimals = "0123456789ABCDEF";
    string result = "123456";

    for (int i = 0; i < 6; i++)
    {
        int randomIndex = rand() % 15;
        result[i] = hexadecimals[randomIndex];
        cout << "Random digit is: " << hexadecimals[randomIndex] << endl;
    }

    cout << "Random hexcode is: " << result << endl;
    return 0;
}
