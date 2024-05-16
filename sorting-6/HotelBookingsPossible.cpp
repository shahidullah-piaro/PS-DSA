//https://www.interviewbit.com/problems/hotel-bookings-possible/
#include <bits/stdc++.h>

using namespace std;

bool hotel(int capacity) {
    vector<int> startTime, endTime;

    // Get start and end times from user
    int numGuests;
    cout << "Enter the number of guests: ";
    cin >> numGuests;

    if (numGuests <= 0) {
        cout << "Invalid number of guests. Please enter a positive integer." << endl;
        return false;
    }

    cout << "Enter the start and end times of each guest's stay (separated by space):" << endl;
    for (int i = 0; i < numGuests; ++i) {
        int start, end;
        cin >> start >> end;

        if (start < 0 || end <= start) {
            cout << "Invalid start or end time for guest " << i + 1 << "." << endl;
            cout << "Start time must be non-negative and end time must be greater than start time." << endl;
            return false;
        }

        startTime.push_back(start);
        endTime.push_back(end);
    }

    // Sort start and end times
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());

    // Check if maximum simultaneous occupancy exceeds capacity
    int currentOccupancy = 0;
    int i = 0, j = 0;
    while (i < startTime.size()) {
        if (startTime[i] <= endTime[j]) {
            currentOccupancy++;
            if (currentOccupancy > capacity) {
                return false;
            }
            i++;
        } else {
            currentOccupancy--;
            j++;
        }
    }

    return true;
}

int main() {
    int capacity;
    cout << "Enter the hotel capacity: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid hotel capacity. Please enter a positive integer." << endl;
        return 1;
    }

    if (hotel(capacity)) {
        cout << "The hotel can accommodate all guests." << endl;
    } else {
        cout << "The hotel cannot accommodate all guests at the same time." << endl;
    }

    return 0;
}
