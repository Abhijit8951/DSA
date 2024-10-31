//Permutation in string
#include <iostream>
#include <string>
using namespace std;

// Function to check if two character count arrays are the same
bool areCountsEqual(const int count1[], const int count2[]) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

// Function to find if a permutation of the substring exists in the main string
bool findPermutationInString(const string& mainStr, const string& subStr) {
    int m = mainStr.length();
    int n = subStr.length();

    // If the substring is longer than the main string, return false
    if (n > m) {
        return false;
    }

    // Count frequency of characters in the substring and initial window of the main string
    int subStrCount[26] = {0}, windowCount[26] = {0};
    for (int i = 0; i < n; i++) {
        subStrCount[subStr[i] - 'a']++;
        windowCount[mainStr[i] - 'a']++;
    }

    // Slide the window over the main string
    for (int i = n; i < m; i++) {
        // If counts match, permutation exists
        if (areCountsEqual(subStrCount, windowCount)) {
            return true;
        }

        // Update the window counts by adding the next character and removing the first character of the window
        windowCount[mainStr[i] - 'a']++;
        windowCount[mainStr[i - n] - 'a']--;
    }

    // Check the last window
    return areCountsEqual(subStrCount, windowCount);
}

int main() {
    string mainStr, subStr;

    cout << "Enter the main string: ";
    cin >> mainStr;

    cout << "Enter the substring: ";
    cin >> subStr;

    if (findPermutationInString(mainStr, subStr)) {
        cout << "A permutation of the substring exists in the main string." << endl;
    } else {
        cout << "No permutation of the substring exists in the main string." << endl;
    }

    return 0;
}
