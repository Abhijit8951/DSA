//Best time to buy and sell stock with transaction fee
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int buy = INT_MIN;
    int sell = 0;

    for (int price : prices) {
        buy = max(buy, sell - price);
        sell = max(sell, buy + price - fee);
    }

    return sell;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    
    int result = maxProfit(prices, fee);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
