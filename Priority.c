#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process processes[], int n) {
    processes[0].completion_time = processes[0].burst_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = processes[0].turnaround_time - processes[0].burst_time;

    for (int i = 1; i < n; ++i) {
        processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",
               processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].priority,
               processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

void priorityScheduling(struct Process processes[], int n) {
    // Sort processes based on arrival time and priority
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            } else if (processes[j].priority == processes[j + 1].priority &&
                       processes[j].arrival_time > processes[j + 1].arrival_time) {
                // If priorities are equal, sort by arrival time
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n);

    // Display the results in the form of a table
    displayResults(processes, n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    // Perform priority scheduling
    priorityScheduling(processes, n);

    return 0;
}