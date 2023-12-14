#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int isSafe(int process, int request[]) {
    for (int i = 0; i < MAX_RESOURCES; ++i)
        if (request[i] > need[process][i] || request[i] > available[i])
            return 0;
    return 1;
}

void grantRequest(int process, int request[]) {
    for (int i = 0; i < MAX_RESOURCES; ++i) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
}

int main() {
    // Initialization code (setting available, max, allocation, need)

    while (1) {
        int process, request[MAX_RESOURCES];
        // Input process number and resource request

        if (isSafe(process, request)) {
            grantRequest(process, request);
            // Display updated state (shortened for brevity)
        } else {
            printf("Request denied. Not in safe state.\n");
        }
    }

    return 0;
}