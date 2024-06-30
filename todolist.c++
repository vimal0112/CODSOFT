#include <iostream>
#include <cstring>
using namespace std;
const int MAX_TASKS = 100;
const int MAX_LENGTH = 256;
struct Task {
    char description[MAX_LENGTH];
    bool completed;
};
void addTask(Task tasks[], int& taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full." << endl;
        return;
    }
    cout << "Enter task description: ";
    cin.ignore();
    cin.getline(tasks[taskCount].description, MAX_LENGTH);
    tasks[taskCount].completed = false;
    taskCount++;
    cout << "Task added." << endl;
}
void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available." << endl;
        return;
    }
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
    }
}
void markTaskCompleted(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available." << endl;
        return;
    }
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}
void removeTask(Task tasks[], int& taskCount) {
    if (taskCount == 0) {
        cout << "No tasks available." << endl;
        return;
    }
    int taskNumber;
    cout << "Enter task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskCount) {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}
int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                removeTask(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
