#include <iostream>
#include <cstring>
using namespace std;

class list
{
public:
    string task;
    string desc;
    bool status = false;
    void add_task()
    {
        cout << "Enter the new task: ";
        cin.ignore();
        getline(cin, task);
        cout << "Description: ";
        getline(cin, desc);
    }

    void change_status()
    {
        status = true;
    }
};

void print_task(list *ToDoList[], int &task_count, string &status)
{
    cout << "\n--- To Do List ---" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i + 1 << ": " << ToDoList[i]->task << endl;
        cout << "Description: " << ToDoList[i]->desc << endl;
        if (ToDoList[i]->status)
        {
            status = "Completed";
        }
        else
        {
            status = "Pending";
        }
        cout << "Status: " << status << endl;
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

int main()
{
    int task_count = 0;
    int option = -1;
    string status;
    int del_task;
    int status_change_task;

    list *ToDoList[10];

    while (option != 0)
    {
        cout << "\n----- Options -----" << endl
             << "1. Add a new task" << endl
             << "2. View all tasks" << endl
             << "3. Remove a task" << endl
             << "4. Mark a task as completed" << endl
             << "0. Exit\n"
             << endl;
        cout << "Choose option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            if (task_count > 9)
            {
                cout << "List is full. Cannot add more tasks." << endl;
            }
            else
            {
                ToDoList[task_count] = new list();
                ToDoList[task_count]->add_task();
                task_count++;
                cout << "Task added successfully." << endl;
            }
            break;

        case 2:
            if (task_count == 0)
            {
                cout << "The to-do list is empty." << endl;
            }
            else
            {
                print_task(ToDoList, task_count, status);
            }
            break;

        case 3:
            if (task_count == 0)
            {
                cout << "The to-do list is empty." << endl;
                break;
            }
            cout << "Enter the task number to remove it: ";
            cin >> del_task;
            del_task--;
            if (del_task < 0 || del_task >= task_count)
            {
                cout << "Invalid task number. Please try again." << endl;
            }
            else
            {
                delete ToDoList[del_task];
                for (int i = del_task; i < task_count - 1; i++)
                {
                    ToDoList[i] = ToDoList[i + 1];
                }
                task_count--;
                if (task_count == 0)
                {
                    cout << "No tasks left in the list." << endl;
                }
                else
                {
                    cout << "Task removed successfully." << endl;
                    print_task(ToDoList, task_count, status);
                }
            }
            break;

        case 4:
            if (task_count == 0)
            {
                cout << "The to-do list is empty." << endl;
                break;
            }
            cout << "Enter the task number to mark it as completed: ";
            cin >> status_change_task;
            status_change_task--;
            if (status_change_task < 0 || status_change_task >= task_count)
            {
                cout << "Invalid task number. Please try again." << endl;
            }
            else
            {
                ToDoList[status_change_task]->change_status();
                cout << "Task status updated successfully." << endl;
                print_task(ToDoList, task_count, status);
            }
            break;

        case 0:
            cout << "Exiting the program..." << endl;
            break;

        default:
            cout << "Invalid input. Please enter a valid option." << endl;
            break;
        }
    }

    for (int i = 0; i < task_count; ++i)
    {
        delete ToDoList[i];
    }

    return 0;
}
