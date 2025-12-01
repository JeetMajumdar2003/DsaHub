#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Meeting {
    public:
    int start; // Start time of the meeting
    int end;   // End time of the meeting
    int pos;   // Position of the meeting
};

// Comparison function to sort meetings according to end time
bool comparator(Meeting m1, Meeting m2) {
    return (m1.end < m2.end);
}

// Function to find the maximum number of meetings that can be accommodated in a single room
void maxMeeting(vector<int> s, vector<int> f) {
    int n = s.size();
    vector<Meeting> m(n);
    for (int i = 0; i < n; i++) {
        m[i].start = s[i];
        m[i].end = f[i];
        m[i].pos = i + 1;
    }

    // Sort all the meetings according to their end time
    sort(m.begin(), m.end(), comparator);

    // Vector to store the selected meetings
    vector<int> answer;
    answer.push_back(m[0].pos);

    // Initialize the end time of the first meeting
    int time_limit = m[0].end;

    // Check for all the remaining meetings
    for (int i = 1; i < n; i++) {
        if (m[i].start > time_limit) {
            // If the current meeting's start time is greater than or equal to the end time of the previous meeting
            answer.push_back(m[i].pos);
            time_limit = m[i].end;
        }
    }

    // Print the selected meetings
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}

int main() {
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    maxMeeting(s, f);
    return 0;
}