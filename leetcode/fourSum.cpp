// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // avoid re-calculating
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] <
                target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;


                int left = j + 1, right = n - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left],
                                                  nums[right]});
                        do {
                            left++;
                        } while (nums[left] == nums[left - 1] && left < right);

                        do {
                            right--;
                        } while (nums[right] == nums[right + 1] && left < right);

                    } else if (sum > target) {
                        right--;

                    } else {
                        left++;
                    }
                }
            }
        }
        return res;
    }
};