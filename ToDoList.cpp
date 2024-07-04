#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int maxTasks = 100;
vector<string> tasks;

void menu();
void viewTasks();
void addTask();
void removeTask();

int main() {
    while (true) {
        int option;
        menu();
        cout << endl << "Select an option: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (option) {
            case 1:
                viewTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
    return 0;
}

void menu() {
    cout << "To-Do List Menu" << endl;
    cout << "[1] View Task(s)" << endl;
    cout << "[2] Add Task" << endl;
    cout << "[3] Remove Task" << endl;
    cout << "[4] Exit" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks have been added yet!\n" << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[ " << i + 1 << " ] " << tasks[i] << endl;
        }
        cout << endl;
    }
}

void addTask() {
    if (tasks.size() < maxTasks) {
        cin.ignore(); 
        cout << "Add task: ";
        string newTask;
        getline(cin, newTask);
        tasks.push_back(newTask);
        cout << "Task added.\n" << endl;
    } else {
        cout << "Oops! You've reached the maximum amount of tasks\n" << endl;
    }
}

void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n" << endl;
        return;
    }

    viewTasks();
    int taskNumber;
    cout << "Select the task number you want to remove: ";
    cin >> taskNumber;

    if (cin.fail() || taskNumber <= 0 || taskNumber > tasks.size()) {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid task number. Please try again." << endl;
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed.\n" << endl;
    }
}

