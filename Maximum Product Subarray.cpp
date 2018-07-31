// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        int positiveMax= 0, negativeMax=0;
        int m = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                swap(positiveMax, negativeMax);
            }
            positiveMax = max(positiveMax * nums[i], nums[i]);
            negativeMax = min(negativeMax * nums[i], nums[i]);
            m = max(m, positiveMax);
        }
        return m;
    }
};