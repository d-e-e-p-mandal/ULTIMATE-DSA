#include <stdio.h>

// Function to calculate the maximum profit
int maxProfit(int* prices, int pricesSize) {
    int lowPrice = prices[0];  // Minimum price so far
    int profit = 0;            // Maximum profit so far

    for (int i = 1; i < pricesSize; i++) {
        if ((prices[i] - lowPrice) < 0) {
            // Found a lower price, better to buy here
            lowPrice = prices[i];
        }
        else if (profit < (prices[i] - lowPrice)) {
            // Found a higher profit, update max profit
            profit = prices[i] - lowPrice;
        }
    }
    return profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, n);
    printf("Maximum Profit: %d\n", result);

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
Time Complexity:  O(n)
  → Single traversal through the array
Space Complexity: O(1)
  → Only constant extra variables used
*/