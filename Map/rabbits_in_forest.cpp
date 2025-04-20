// Rabbits In Forest(LC: 781)
// There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
// Given the array answers, return the minimum number of rabbits that could be in the forest.
// Input: answers = [1,1,2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit that answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int findRabbits(vector<int> answers) {
    int total = 0;
    unordered_map <int,int> mpp;
    for (int i : answers) mpp[i]++;

    for (auto& p : mpp) {
        total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
    }
    
    return total;
}

int main() {
    vector<int> answers = {1, 1, 2};
    int res = findRabbits(answers);

    cout << "The numbers of rabbits in the forest are: " << res << endl;

    return 0;
}