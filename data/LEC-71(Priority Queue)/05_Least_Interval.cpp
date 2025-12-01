#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int leastTime(vector<char>& tasks, int cooldown) {
    // 1. Frequency map to count occurrences of each task
    unordered_map<char, int> freq;
    for (char task : tasks) {
        freq[task]++;
    }

    // 2. Max-heap to store the frequencies of tasks
    priority_queue<int> pq;
    for (auto it : freq) {
        pq.push(it.second);
    }

    int time = 0; // Total time to complete all tasks
    while (!pq.empty()) {
        vector<int> temp; // Temporary storage for tasks during cooldown
        int i = 0;
        while (i <= cooldown) {
            if (!pq.empty()) {
                if (pq.top() > 1) {
                    // Decrease frequency and store in temp if more instances are left
                    temp.push_back(pq.top() - 1);
                }
                pq.pop(); // Remove the task from the heap
            }
            time++; // Increment time for each unit of work or cooldown
            if (pq.empty() && temp.size() == 0) {
                break; // Break if no tasks are left to process
            }
            i++;
        }
        // Push remaining tasks back into the heap
        for (int t : temp) {
            pq.push(t);
        }
    }
    return time; // Return the total time taken
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B'};
    int cooldown = 2;

    int time = leastTime(tasks, cooldown);
    cout << "Total time to complete all tasks: " << time << endl;
    return 0;
}