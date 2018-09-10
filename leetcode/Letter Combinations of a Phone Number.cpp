// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// 2 abc, 3 def, 4 ghi, 5 jkl, 6 mno, 7 pqrs, 8 tuv, 9 wxyz

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <bits/stdc++.h>
#include <list>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        const string params[] = {{},      {},      {"abc"},  {"def"}, {"ghi"},
                                 {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
        vector<string> result;
        if (digits == "")
            return result;
        result.push_back("");
        for (int i = 0; i < digits.length(); i++) {
            vector<string> tempstr;
            string s = params[digits[i] - '0'];
            for (int j = 0; j < result.size(); j++) {
                for (int k = 0; k < s.size(); k++) {
                    tempstr.push_back(result[j] + s[k]);
                }
            }
            result.swap(tempstr);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> result = Solution().letterCombinations("23");
    for (auto t : result) {
        cout << t << " ";
    }
    return 0;
}
