// Happy Number
// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.
#include<iostream>
using namespace std;

bool isHappy(int  num) {
    if(num == 1 || num == 7) {
        return true;
    } else if(num < 10) {
        return false;
    } else {
        int sum = 0;
        while(num > 0) {
            int temp = num%10;
            sum += temp*temp;
            num /= 10;
        }
        return isHappy(sum);
    }
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if(isHappy(num)) {
        cout << "This is a happy number." << endl;
    } else {
        cout << "This is not a happy number." << endl;
    }
}