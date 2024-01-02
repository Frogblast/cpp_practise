#include <iostream>
#include <vector>
#include <fstream> // filestream, has datatype fstream that has the functions open(filepath, type of operation)
#include <string>

using namespace std;

void viewList();
bool addToList(string task);
bool saveListToFile();
void exit(bool *ptr);
string txtPath = "resources/todo_list.txt";
string newTask;

// instantiate a collection of some sort for strings that should be added to the list
vector<string> newTasks;
fstream todoList;

int main()
{
    bool running{true};
    // ask if user wants to see current list, add to the list or quit and save the changes
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
            getline(cin, newTask); // instead of "cin >> newTask" which only reads a word at a time with spaces as delimiters, use
                                        //getline(istream, string) to get the whole sentence.
            if(addToList(newTask)){
                cout<<"Added: "<<newTask<<endl;
            };
            break;
        case 3:
            saveListToFile();
            exit(&running);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}

// show the list
void viewList()
{
    string task;
    todoList.open(txtPath, ios::in); // Parameters are the path and the mode of operation
    // Only operate if the fstream is open
    if (todoList.is_open())
    {
        // while loop to access every line of text: access first line, store in variable and write out.
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

// add to the list
bool addToList(string task)
{
    todoList.open(txtPath, ios::app); //ios::app (append) to existing file. If it does not exist it creates a new.
                                        //ios::out will only create a new file and overwrite the existing file.
    if (todoList.is_open())
    {
        todoList << task<<"\n";
        todoList.close();
        return true;
    }
    else
    {
        return false;
    }
}

// save list to file
bool saveListToFile()
{
}

// quit the program and save the changes
void exit(bool *ptr)
{
    saveListToFile();
    *ptr = false;
}