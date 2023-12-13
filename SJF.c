#include <stdio.h>

int main() {
    int bt[20], at[20], rt[20], completiontime, i, smallest;
    int remain = 0, time, n, avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("\n\nProcess\t| Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time\n\n");
    for (time = 0; remain != n; time++) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (smallest == -1 || rt[i] < rt[smallest]) {
                    smallest = i;
                }
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            completiontime = time + 1;
            int tat = completiontime - at[smallest];
            int wt = tat - bt[smallest];
            printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", smallest + 1, at[smallest], bt[smallest], completiontime, tat, wt);
            avg_wt += wt;
            avg_tat += tat;
        }
    }
    printf("\nAverage Waiting time = %f\n", (float)avg_wt / n);
    printf("\nAverage Turn Around time = %f\n", (float)avg_tat / n);
    return 0;
}