//Sieve Of Eratosthenses(Prime Number)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 50;
    if (n <= 2) return 0;

    vector<bool> isPrime(n, true);
    int count = 0;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }
    cout << count << endl;

    return 0;

    
}