#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct todo_list
{
    int id;
    std::string task;
};

int ID = 0;
std::vector<todo_list> tasks;

void DisplayMenu();
void Add_Task();
void Display_Tasks();
void Mark_Task_Completed();
void Edit_Task();
void Delete_Task();

using namespace std;

int main()
{
    system("cls");
    while (true)
    {
        int choice;
        DisplayMenu();

        cout << "Enter Your Choice : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            Add_Task();
            break;

        case 2:
            Display_Tasks();
            break;

        case 3:
            Mark_Task_Completed();
            break;

        case 4:
            Edit_Task();
            break;

        case 5:
            Delete_Task();
            break;

        default:
            cout << "!!!Invalid choice" << endl;
            break;
        }
    }
}

void DisplayMenu()
{
    cout << "\n---------- To-Do List Menu -----------\n";
    cout << "1. Add Task\n";
    cout << "2. Display Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Edit Task\n";
    cout << "5. Delete Task\n";
    cout << "0. Exit\n";
    cout << "-----------------------------------------\n";
}

void Add_Task()
{
    system("cls");

    todo_list todo;

    cout << "Enter New Task : " << endl;
    cin.get();
    getline(cin, todo.task);

    char save;
    cout << "Save Task ? (y/n) : " << endl;
    cin >> save;

    if (save == 'y')
    {
        ID++;
        todo.id = ID;
        tasks.push_back(todo);

        char more;
        cout << "Add More Task? (y/n): ";
        cin >> more;

        if (more == 'y')
        {
            Add_Task();
        }
        else
        {
            cout << "Task Added Successfully!" << endl;
            return;
        }
    }
    system("cls");
}

void Display_Tasks()
{
    system("cls");

    cout << "Tasks : " << endl;

    for (const auto &task : tasks)
    {
        cout << task.id << " : " << task.task << endl;
    }

    char exit;
    cout << "Exit ?(y/n) : " << endl;
    cin >> exit;

    if (exit != 'y')
    {
        Display_Tasks();
    }

    system("cls");
}

void Mark_Task_Completed()
{
    system("cls");

    int task_id;
    cout << "Enter Task ID to mark as completed: ";
    cin >> task_id;

    for (auto &task : tasks)
    {
        if (task.id == task_id)
        {
            task.task += " [Completed]";
            break;
        }
    }

    cout << "Task marked as completed successfully!" << endl;

    char more;
    cout << "Mark another task as completed? (y/n): ";
    cin >> more;

    if (more == 'y')
    {
        Mark_Task_Completed();
    }

    system("cls");
}

void Edit_Task()
{
    system("cls");

    int task_id;
    cout << "Enter Task ID to edit: ";
    cin >> task_id;

    for (auto &task : tasks)
    {
        if (task.id == task_id)
        {
            cout << "Enter new task description: ";
            cin.ignore();
            getline(cin, task.task);
            break;
        }
    }

    cout << "Task edited successfully!" << endl;

    char more;
    cout << "Edit another task? (y/n): ";
    cin >> more;

    if (more == 'y')
    {
        Edit_Task();
    }

    system("cls");
}

void Delete_Task()
{
    system("cls");

    int task_id;
    cout << "Enter Task ID to delete: ";
    cin >> task_id;

    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [task_id](const todo_list &task){ return task.id == task_id; }), tasks.end());

    cout << "Task deleted successfully!" << endl;

    char more;
    cout << "Delete another task? (y/n): ";
    cin >> more;

    if (more == 'y')
    {
        Delete_Task();
    }

    system("cls");
}
