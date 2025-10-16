# Best Time to Buy and Sell Stock

[LeetCode Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

---

## 📌 Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `iᵗʰ` day.  

You want to **maximize your profit** by choosing a single day to **buy one stock** and choosing a **different day in the future** to **sell that stock**.  

Return the maximum profit you can achieve from this transaction.  
If no profit is possible, return `0`.

---

## ✨ Examples

### Example 1
**Input:**  
`prices = [7,1,5,3,6,4]`  

**Output:**  
`5`  

**Explanation:**  
Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = `6 - 1 = 5`.  
You must buy before you sell.

---

### Example 2
**Input:**  
`prices = [7,6,4,3,1]`  

**Output:**  
`0`  

**Explanation:**  
No transactions can result in profit.

---

## 🎯 Constraints
- `1 <= prices.length <= 10^5`  
- `0 <= prices[i] <= 10^4`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single traversal through prices array |
| **Space Complexity** | `O(1)` — Constant extra variables |

---

## 🏢 Company Tags
Amazon, Microsoft, Facebook, Google, Apple, Flipkart, Goldman Sachs, Adobe, Bloomberg, Oracle, TCS, Infosys

---

## 🏷️ Topic Tags
- Array  
- Dynamic Programming  
- Greedy  
- Algorithms

---

## 💡 Approach – Single Pass (Kadane’s Logic Adaptation)
This problem can be viewed as finding the **maximum difference** between two elements such that the smaller element appears **before** the larger one.

### 🔍 Steps:
1. Initialize `min_price` as the first day's price.  
2. Initialize `max_profit` as 0.  
3. Traverse each day's price:
   - Update `min_price` if a smaller price is found.  
   - Compute current profit = `price - min_price`.  
   - Update `max_profit` if current profit is higher.  
4. Return `max_profit`.

---

## 🧠 Algorithm
1. Start with `min_price = prices[0]` and `max_profit = 0`.  
2. For each `price` in array:
   - `min_price = min(min_price, price)`  
   - `max_profit = max(max_profit, price - min_price)`  
3. Return `max_profit`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        min_price = min(min_price, price);
        max_profit = max(max_profit, price - min_price);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices); // Output: 5
    return 0;
}
```