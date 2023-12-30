#include <iostream>

using namespace std;

int main()
{
    string operand1, operand2;
    char _operator;
    bool running = true;

    while (running)
    {
        cout << "Write two numbers" << endl;
        cin >> operand1 >> operand2;

        cout << "Enter the operator: +, -, *, /" << endl;
        cin >> _operator;

        float result;

        switch (_operator)
        {
        case '+':
            result = stoi(operand1) + stoi(operand2);
            cout << "Sum is: " << result << endl;
            break;
        case '-':
            result = stoi(operand1) - stoi(operand2);
            cout << "Diffence is: " << result << endl;
            break;
        case '*':
            result = stoi(operand1) * stoi(operand2);
            cout << "Product is: " << result << endl;
            break;
        case '/':
            result = static_cast<float>(stoi(operand1)) / static_cast<float>(stoi(operand2));
            cout << "Quotient is: " << result << endl;
            break;

        default:
            break;
        }
        cout << "Do you want to quit? y/n" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            cout << "Quitting program" << endl;
            running = false;
        }
    }
    return 0;
}