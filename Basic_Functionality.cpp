#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool isDone;
    string duedate;

    Task(string desc = "Default",string due="Default", bool done = false) : description(desc),duedate(due), isDone(done) {}
};


// Funtion To Add Tasks 
void Add_Tasks(vector<Task> &tasks) {

    string task_description;
    string due_date;
     
        cout<<" Enter The Task You Want To Add : ";
        cin.ignore();
        getline(cin,task_description);
        cout<<" \n Enter it's Due Date :";
        getline(cin,due_date);

        tasks.push_back((task_description,due_date));

}

// Function to display tasks
void Tasks_display(vector<Task> &tasks) {
        // Loop through each task and display its status
        for (int i = 0; i < tasks.size(); i++) {
            cout << "Task " << i + 1 << ": " 
                 << tasks[i].description 
                 << " [" << (tasks[i].isDone ? " Done " : " Pending ") << "]" << endl;
        
    }
    cout << "*_______________________________*" << endl;
}

// Function to mark a task as done
void MarkTaskDone(vector<Task> &tasks) {
    int TaskNumber;
    cout << "\n Enter Task number to mark as done: ";
    cin >> TaskNumber;

    if (TaskNumber < 1 || TaskNumber > tasks.size()) {
        cout << "\n Not A Valid Task Number" << endl;
    } else {
        tasks[TaskNumber - 1].isDone = true;
        cout << "Task " << TaskNumber << " marked as done!" << endl;
    }
}

// Function to delete a task
void DeleteTask(vector<Task> &tasks) {
    int del_task;
    cout << "Enter the Task number to be deleted: ";
    cin >> del_task;

    if (del_task < 1 || del_task > tasks.size()) {
        cout << "Invalid Task" << endl;}
        else{

            tasks.erase(tasks.begin()+del_task-1);

        cout << "Task " << del_task << " deleted successfully!" << endl;
    }
}

int main() {
    vector<Task> tasks;  // Array of tasks (maximum 10)
    int Tasks_count=0;
    int option = -1;

    // Loop to access the functions
    while (option != 5) {
        cout << "  TO DO LIST  " << endl;
        cout << "__________________" << endl;
        cout << "1: Add a Task " << endl;
        cout << "2: View The Tasks " << endl;
        cout << "3: Mark A Task Done " << endl;
        cout << "4: Remove a Task " << endl;
        cout << "5: Terminate The Program " << endl;
        cin >> option;

        switch (option) {
            case 1: {
                Add_Tasks(tasks);
            } break;

            case 2: {
                Tasks_display(tasks);
            } break;

            case 3: {
                MarkTaskDone(tasks);
            }

            case 4: {
                DeleteTask(tasks);
            } break;

            case 5: {
                cout << " Program has been terminated." << endl;
            } break;

            default: {
                cout << " Not a valid option! " << endl;
            }
        }
    }

    return 0 ;
}