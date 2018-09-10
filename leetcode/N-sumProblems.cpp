// 三数之和/n数之和
// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 通用方法 n-sums
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;
// 三数之和/n数之和
// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 通用方法 n-sums
// 时间效率不是很高

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int &target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = nsums(nums, 4, target);

        set<vector<int>> res_set;
        for (auto i = result.begin(); i < result.end(); i++) {
            auto t = *i;
            sort(t.begin(), t.end());
            if (res_set.count(t) != 0) {
                result.erase(i);
                i--;
            } else {
                res_set.insert(t);
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result = nsums(nums, 3, 0);

        set<vector<int>> res_set;
        for (auto i = result.begin(); i < result.end(); i++) {
            auto t = *i;
            sort(t.begin(), t.end());
            if (res_set.count(t) != 0) {
                result.erase(i);
                i--;
            } else {
                res_set.insert(t);
            }
        }
        return result;
    }

    vector<vector<int>> nsums(vector<int> nums, int n, int sum)
    {
        // 算法的时间复杂度
        vector<vector<int>> result;
        if (n <= 0 || nums.size() < n) {
            return result;
        }

        if (n == 1) {
            if (count(nums.begin(), nums.end(), sum) != 0) {
                //找到元素
                // cout << "n = 1, find ： " << sum<<endl;
                vector<int> tmp;
                tmp.push_back(sum);
                result.push_back(tmp);
                return result;
            } else {
                //找不到元素
                // cout << "n = 1, find nothing"<<endl;
                return result;
            }
        }

        set<int> elements;
        vector<int> tmp = nums;
        for (auto it = tmp.begin(); it < tmp.end(); it++) {
            int minsum = 0;
            for (int i = 0; i < n; i++) {
                minsum += tmp[i];
            }
            if (minsum > sum)
                return result;
            if (elements.count(*it) != 0) {
                // 已经查找过这个元素
                // cout << "already searched" << *it <<endl;
                continue;
            }
            int element = *it;

            // cout << "s:" << element << endl;

            elements.insert(element);
            tmp.erase(it);
            it--;
            // for(auto i : tmp){
            //      cout << i << ",";
            // }
            // cout << endl;
            vector<vector<int>> sub = nsums(tmp, n - 1, sum - element);
            if (sub.empty()) {
                continue;
            } else {
                for (auto i : sub) {
                    // 在所得解中加入当前元素
                    if (i.empty())
                        continue;
                    i.push_back(element);
                    // for(auto t : i){
                    //     cout << t << ",";
                    // }
                    // cout << endl;
                    // 将解存入result
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> v;
    for (int d; std::cin >> d; v.push_back(d)) {
    }
    Solution s;
    vector<vector<int>> res = s.threeSum(v);
    cout << "=========result=======" << endl;
    for (auto i : res) {
        for (auto val : i) {
            cout << val << ",";
        }
        cout << endl;
    }
}