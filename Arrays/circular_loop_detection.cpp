// Circular array loop
// You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:
// If nums[i] is positive, move nums[i] steps forward, and
// If nums[i] is negative, move nums[i] steps backward.
// Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
// A cycle in the array consists of a sequence of indices seq of length k where:
// Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
// Every nums[seq[j]] is either all positive or all negative.
// k > 1
// Return true if there is a cycle in nums, or false otherwise.
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the next index in a circular manner
int nextIndex(vector<int>& nums, int i) {
    int n = nums.size();
    return ((i + nums[i] % n) + n) % n; // handles negative values correctly
}

// Function to detect a circular loop
bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int slow = i;
        int fast = nextIndex(nums, i);

        // Move both pointers as long as they are going in the same direction
        while (nums[slow] * nums[fast] > 0 &&
               nums[slow] * nums[nextIndex(nums, fast)] > 0) {

            // If they meet, and it's not a single-element loop
            if (slow == fast) {
                if (slow != nextIndex(nums, slow)) {
                    return true;
                }
                break;
            }

            // Move slow by one and fast by two
            slow = nextIndex(nums, slow);
            fast = nextIndex(nums, nextIndex(nums, fast));
        }
    }
    return false;
}

int main() {
    // Example input
    vector<int> nums = {2, -1, 1, 2, 2};

    if (circularArrayLoop(nums)) {
        cout << "Circular loop exists!" << endl;
    } else {
        cout << "No circular loop found." << endl;
    }

    return 0;
}