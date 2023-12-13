#include <iostream>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int remainingTime;
};

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    int currentTime = 0;

    while (true) {
        bool allProcessesCompleted = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                allProcessesCompleted = false;

                int executionTime = min(timeQuantum, processes[i].remainingTime);
                currentTime += executionTime;
                processes[i].remainingTime -= executionTime;

                if (processes[i].remainingTime == 0) {
                    processes[i].completionTime = currentTime;
                }
            }
        }

        if (allProcessesCompleted) {
            break;
        }
    }
}

int main() {
    int n, timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    cout << "Enter arrival time and burst time for processes:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    roundRobinScheduling(processes, n, timeQuantum);

    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << processes[i].completionTime << endl;
    }

    return 0;
}
