// Given an array, rotate the array to the right by k steps, where k is non-negative.

// Example 1:

// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

// Note:

// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

class Solution {
public:
    // solution 1: shift k times, with O(1) extra space, O(kn) time;
    // TLE..
    void rotate1(vector<int> &nums, int k)
    {
        int tail = nums.back();
        for (int i = 0; i < k; i++) {
            for (int t = 1; t < nums.size(); t++) {
                nums[t] = nums[t - 1];
            }
            nums[0] = tail;
            tail = &nums.end();
        }
    }

    // solution 2: shift 1 time, with O(k) space, O(n) time
    // AC
    void rotate2(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> temp;
        for (int i = 0; i < k; i++) {
            temp.push_back(nums[n - k + i]);
        }
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }

};