#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// Shared resource
int counter = 0;

// Synchronization mutex
mutex counterMutex;

// Function to increment the counter in a synchronized manner
void incrementCounter() {
    for (int i = 0; i < 20; ++i) {
        // Lock the mutex before accessing the critical section
        lock_guard<mutex> lock(counterMutex);
        counter++;
    }
}

int main() {
    // Create two threads
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    // Wait for both threads to finish
    thread1.join();
    thread2.join();

    // Print the final value of the counter
    cout << "Final Counter Value: " << counter << endl;

    return 0;
}