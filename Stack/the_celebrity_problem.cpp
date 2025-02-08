//The celebrity problem
//A celebrity is a person who is known to all but does not know anyone at a party. 
//A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the 
//party such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
//You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
// Note: Follow 0-based indexing.
// Examples:
// Input: mat[][] = [[0 1 0], [0 0 0], [0 1 0]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
// Input: mat[][] = [[0 1], [1 0]]
// Output: -1
// Explanation: The two people at the party both know each other. None of them is a celebrity.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(vector<vector<int>>& mat, int a, int b) {
    return mat[a][b] == 1;
}

int findCelebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    stack<int> s;
    
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    
    while (s.size() > 1) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        
        if (knows(mat, a, b)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }
    
    int candidate = s.top();
    
    for (int i = 0; i < n; i++) {
        if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
            return -1;
        }
    }
    
    return candidate;
}

int main() {
    int n;
    cout << "Enter number of people: ";
    cin >> n;
    
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the matrix values: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    int celebrity = findCelebrity(mat);
    
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person is: " << celebrity << endl;
    }
    
    return 0;
}