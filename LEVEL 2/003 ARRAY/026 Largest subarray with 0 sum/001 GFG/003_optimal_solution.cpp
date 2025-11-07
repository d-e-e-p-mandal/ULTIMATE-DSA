#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        int sum = 0;
        unordered_map<int, int> mp;  // stores (prefix sum → first index where it occurred)
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];  // cumulative sum
            
            // ✅ Case 1: if entire subarray from 0 to i sums to 0
            if (sum == 0) {
                maxLen = i + 1;
            }
            // ✅ Case 2: if same prefix sum seen before
            // subarray between previous index+1 and i has sum 0
            else if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            }
            // ✅ Case 3: store the first occurrence of this prefix sum
            else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};

// 🧩 Main function for demonstration
int main() {
    Solution obj;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    
    cout << "Input Array: [15, -2, 2, -8, 1, 7, 10, 23]\n";
    int result = obj.maxLength(arr);
    
    cout << "Length of longest subarray with sum = 0: " << result << endl;
    
    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input Array: [15, -2, 2, -8, 1, 7, 10, 23]
Length of longest subarray with sum = 0: 5
----------------------------------------

✅ Time Complexity: O(n)
   - Single traversal of array, each prefix sum lookup O(1) (unordered_map)

✅ Space Complexity: O(n)
   - In worst case, we store n prefix sums in the hashmap

✅ Explanation:
   - Use cumulative sum and a hashmap to track first occurrences.
   - If current prefix sum has appeared before, subarray between
     previous occurrence and current index has zero sum.
   - Keep track of maximum such length.
----------------------------------------
*/