#include <bits/stdc++.h>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;
 
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
 
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
 
    // shmat to attach to shared memory
    char* str = (char*)shmat(shmid, (void*)0, 0);
 
    cout << "Write Data : ";
    cin.getline(str, 1024);
 
   // cout << "Data written in memory: " << str << endl;
 
    // detach from shared memory
    shmdt(str);
    char* str2 = (char*)shmat(shmid, (void*)0, 0);
 
    cout << "Data read from memory:" << str2;
 
    // detach from shared memory
    shmdt(str2);
 
    // destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);
 
 return 0;
}