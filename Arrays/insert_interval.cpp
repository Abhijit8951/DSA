// Insert Interval
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. 
// You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.
// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }

    return res;        
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    cout << "Merged Intervals: " << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}