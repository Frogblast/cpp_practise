#include <iostream>
#include <vector>
#include <fstream> // filestream, has datatype fstream that has the functions open(filepath, type of operation)
#include <string>
#include <conio.h> // for "getch() function"

using namespace std;

void viewList();
bool addToList(string task);
void exit(bool *ptr);
string txtPath = "resources/todo_list.txt";
string newTask;
void waitForUserInputToContinue();

// Instantiate a collection of some sort for strings that should be added to the list
vector<string> newTasks;
fstream todoList;

int main()
{
    bool running{true};
    // While loop to ask if user wants to see current list, add to the list or quit and save the changes
    while (running)
    {
        cout << "Select an option:\n"
             << endl;
        cout << "View current list (1)\nAdd to the list (2)\nQuit and save changes (3)" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewList();
            break;
        case 2:
            cout << "Enter new task" << endl;
            cin.ignore();
            /*Instead of "cin >> newTask" which only reads a word at a time with spaces as delimiters,
            use getline(istream, string) to get the whole sentence.
            */
            getline(cin, newTask);
            if (addToList(newTask))
            {
                cout << "Added: " << newTask << endl;
            };
            break;
        case 3:
            exit(&running);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        getch(); // Wait for user to hit enter (from library conio.h)
        system("CLS");
    }
    return 0;
}

// Show the list
void viewList()
{
    string task;
    // Parameters of the fstream-function "open" are the path of the text file and the mode of operation (ios::in for reading)
    todoList.open(txtPath, ios::in);
    // Only operate if the fstream is open
    if (todoList.is_open())
    {
        cout << "List: " << endl;
        // Iterate through the fstream to access each line of the file
        while (getline(todoList, task))
        {
            cout << task << endl;
        }
        // Close and release the fstream after use
        todoList.close();
    }
}

// Add to the list, sending a true boolean value back if successful
bool addToList(string task)
{
    todoList.open(txtPath, ios::app); // ios::app (append) to existing file. If it does not exist it creates a new.
                                      // ios::out would create a new file, overwriting the existing one.
    if (todoList.is_open())
    {
        // Uses data-stream to put the new task (string) in to the fstream object followed by a new line
        todoList << task << "\n";
        todoList.close();
        return true;
    }
    else
    {
        return false;
    }
}

// Quit the program and save the changes
void exit(bool *ptr)
{
    *ptr = false;
}
