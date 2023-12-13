#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>
// Include this header for fork()

int main() 
{
    int pid, pid1, pid2;

    pid = fork();

    if (pid == -1) {
        printf("Error in process creation");
        exit(1);
    }

    if (pid != 0) {
        pid1 = getpid();
        printf("\nThe Parent Process ID is %d \n", pid1);
    } else {
        pid2 = getpid();
        printf("\nThe Child Process Id is %d \n", pid2);
    }

    return 0;
}
