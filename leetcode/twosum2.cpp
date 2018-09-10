// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

// Note:

// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
// Example:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

class Solution {
public:
    //solution 1 :hash 表 O(n)复杂度，O(n)额外空间
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(int i = 0; numbers[i]<=target&& i < numbers.size(); i++){
            if(hash.find(target - numbers[i])!=hash.end()){//find
                result.push_back(hash[target - numbers[i]]+1);
                result.push_back(i+1);
                return result;
            }else{
                hash[numbers[i]] = i;
            }
        }
    }

    //solution 2: O(n)复杂度，O(1)额外空间
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> result;
        for (i = 0; i<j;){
            if(numbers[i] + numbers[j] == target){
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
    }

};