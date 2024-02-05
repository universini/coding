#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a meeting
struct Meeting {
    int start;
    int end;
};

// Custom comparator for sorting meetings based on start time
bool compareMeetings(const Meeting& a, const Meeting& b) {
    return a.start < b.start;
}

int minMeetingRooms(vector<Meeting>& meetings) {
    if (meetings.empty()) {
        return 0;
    }

    // Sort meetings by start time
    sort(meetings.begin(), meetings.end(), compareMeetings);

    // Priority queue to store end times of ongoing meetings
    priority_queue<int, vector<int>, greater<int>> endTimes;

    // Add the end time of the first meeting
    endTimes.push(meetings[0].end);

    // Iterate through the sorted meetings
    for (int i = 1; i < meetings.size(); ++i) {
        // If the start time of the current meeting is greater than or equal to
        // the earliest end time in the priority queue, we can reuse the room.
        if (meetings[i].start >= endTimes.top()) {
            endTimes.pop();
        }

        // Add the end time of the current meeting to the priority queue
        endTimes.push(meetings[i].end);
    }

    // The size of the priority queue is the minimum number of rooms required
    return endTimes.size();
}

int main() {
    // Example usage:
    vector<Meeting> meetings = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of rooms required: " << minMeetingRooms(meetings) << endl;

    return 0;
}
