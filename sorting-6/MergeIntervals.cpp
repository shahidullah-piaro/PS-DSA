//https://leetcode.com/problems/merge-intervals/description/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
     if (intervals.empty()) {
        return {};
    }

    // Sort intervals based on their starting points
    sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[0] < interval2[0];
    });

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        const vector<int>& currentInterval = intervals[i];
        vector<int>& lastMergedInterval = mergedIntervals.back();

        // Check for overlap
        if (lastMergedInterval[1] >= currentInterval[0]) {
            // Merge intervals
            lastMergedInterval[1] = max(lastMergedInterval[1], currentInterval[1]);
        } else {
            // No overlap, add new interval to result
            mergedIntervals.push_back(currentInterval);
        }
    }

    return mergedIntervals;
}

int main() {
    int numIntervals;
    cout << "Enter the number of intervals: ";
    cin >> numIntervals;

    vector<vector<int>> intervals(numIntervals, vector<int>(2));  // Pre-allocate for efficiency

    cout << "Enter the starting and ending points of each interval (space-separated):\n";
    for (int i = 0; i < numIntervals; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    cout << "Merged intervals:\n";
    for (const vector<int>& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}
