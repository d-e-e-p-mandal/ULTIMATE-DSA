#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;  // Base case: prefix sum 0 exists once
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            int remaining = sum - k;
            cnt += prefixSum[remaining];  // count all previous prefix sums that match
            
            prefixSum[sum]++;  // record this prefix sum
        }
        
        return cnt;
    }
};

int main() {
    vector<int> nums = {10, 2, -2, -20, 10};
    int k = -10;

    Solution obj;
    int result = obj.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Number of subarrays with sum -10 = 3

-----------------------------------
✅ Time Complexity: O(n)
   - Each element is processed once.
   - Hashmap lookup and update operations are O(1) on average.

✅ Space Complexity: O(n)
   - In the worst case, all prefix sums are unique, stored in the hashmap.

-----------------------------------
🔍 Dry Run (nums = [10, 2, -2, -20, 10], k = -10)

i | nums[i] | sum | sum-k | prefixSum[sum-k] | cnt | prefixSum after step
-----------------------------------------------------------------------
0 |   10    |  10 |  20   |       0          |  0  | {0:1, 10:1}
1 |    2    |  12 |  22   |       0          |  0  | {0:1,10:1,12:1}
2 |   -2    |  10 |  20   |       0          |  0  | {0:1,10:2,12:1}
3 |  -20    |  -10|   0   |       1          |  1  | {0:1,10:2,12:1,-10:1}
4 |   10    |   0 |  10   |       2          |  3  | {0:2,10:2,12:1,-10:1}

✅ Final Answer = 3
-----------------------------------
*/