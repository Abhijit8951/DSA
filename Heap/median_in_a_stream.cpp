// Median in a stream
// Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
// Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
// For example :
// [2,3,4] - median is 3.
// [2,3] - median is floor((2+3)/2) = 2.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int signum(int a, int b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}

void callMedian(int element, priority_queue<int> &maxi, 
                priority_queue<int, vector<int>, greater<int>> &mini, int &median) {
    switch(signum(maxi.size(), mini.size())) {
        case 0:
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        case 1:
            if (element > median) {
                mini.push(element);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2;
            break;
        case -1:
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for (int i = 0; i < n; i++) {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();
    
    vector<int> medians = findMedian(arr, n);
    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;
    return 0;
}