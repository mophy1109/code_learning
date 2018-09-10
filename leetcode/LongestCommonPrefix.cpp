// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string LCP = "";
        if (strs[0].length() == 0) return LCP;
        for (int i = 0; i < strs[0].length(); i++) {
            int j;
            for (j = 0; j < strs.size(); j++){
                if (strs[j][i] != strs[j][0]) return LCP;
            }
            LCP += strs[0][i];
        }
        return LCP;
    }
};