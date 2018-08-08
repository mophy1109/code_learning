// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0;
             i < nums.size() - 2 && (nums[i] + nums[i + 1] + nums[i + 2] <= 0);
             i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                if (nums[front] + nums[back] < target) {
                    front++;
                } else if (nums[front] + nums[back] > target) {
                    back--;
                } else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    result.push_back(triplet);
                    while (nums[front] == triplet[1])
                        front++;
                }
            }
            while (nums[i + 1] == nums[i] && i+1<nums.size())
                i++;
        }
        return result;
    }
};