// Brute Force Solution : 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyingPrice = INT_MAX; // Minimum price to buy
        int maxProfit = 0;         // Maximum profit found so far

        for (int i = 0; i < n-1; i++) {
            buyingPrice = prices[i];
            for(int j = i+1; j<n; j++) {
                maxProfit = max(maxProfit, prices[j] - buyingPrice);
            }
        
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}

/*
Output:
Maximum Profit: 5

Explanation:
Buy on day 2 (price = 1)
Sell on day 5 (price = 6)
Profit = 6 - 1 = 5

------------------------------------
Time Complexity:  O(n^2)
  → Two time traversal through price list
Space Complexity: O(1)
  → Constant extra space used
*/