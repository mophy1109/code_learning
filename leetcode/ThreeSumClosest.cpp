// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int minimum = abs(sum - target);
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int findnumber = target - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while (front < back) {
                int value = nums[i] + nums[front] + nums[back];
                if (abs(value - target) < minimum) {
                    minimum = abs(value - target);
                    sum = value;
                    if (minimum == 0)
                        return sum;
                }
                if (nums[front] + nums[back] < findnumber) {
                    front++;
                } else {
                    //此处不能写 nums[front] + nums[back] > findnumber 作为条件，
                    //因为minimum初始化用了前3项，若数组只有三项用此条件将产生死循环
                    back--;
                }
            }
        }
        return sum;
    }
};