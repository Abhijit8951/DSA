//Find square root of a number using binary search
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter  a number: ";
    cin >> n;

    int s = 0;
    int e = n;
    //long long int mid = s + (e - s)/2;

    long long int ans = -1;
    while(s <= e){
        long long int mid = s + (e - s)/2;
        long long int square = mid * mid;

        if(square == n){
            cout << mid << endl;
            return 0;
        }

        if(square < n){
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}