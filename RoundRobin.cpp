#include <iostream>
#include <vector>
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

    // Calculate turnaround time and waiting time
    double totalTurnaroundTime = 0, totalWaitingTime = 0;

    cout << "\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        processes[i].completionTime = max(processes[i].completionTime, processes[i].arrivalTime);
        int turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        int waitingTime = turnaroundTime - processes[i].burstTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << processes[i].completionTime << "\t\t"
             << turnaroundTime << "\t\t" << waitingTime << endl;
    }

    double avgTurnaroundTime = totalTurnaroundTime / n;
    double avgWaitingTime = totalWaitingTime / n;

    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;

    return 0;
}
