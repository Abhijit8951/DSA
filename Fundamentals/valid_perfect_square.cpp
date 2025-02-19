// Valid Perfect Square
//Given a positive integer num, return true if num is a perfect square or false otherwise.
// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
// You must not use any built-in library function, such as sqrt.
// Example 1:
// Input: num = 16
// Output: true
// Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
#include <iostream>
#include <cmath> 
using namespace std;

bool isInteger(double number) {
    double intPart;
    double fracPart = modf(number, &intPart);
    return fabs(fracPart) < 1e-5; 
}

bool isPerfectSquare(int number) {
    if (number < 0) {
        return false;
    }
    if (number == 0 || number == 1) {
        return true;
    }
    
    double guess = number;
    double epsilon = 0.00001;

    while (fabs(guess - number / guess) > epsilon) {
        guess = (guess + number / guess) / 2;
    }
    
    return isInteger(guess);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    if (isPerfectSquare(number)) {
        cout << number << " is a perfect square." << endl;
    } else {
        cout << number << " is not a perfect square." << endl;
    }
    
    return 0;
}