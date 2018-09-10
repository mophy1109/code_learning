// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen(res, "", n, 0);
        return res;
    }
    
    void gen(vector<string> &res, string str, int n, int m){
        if(m== 0 && n==0){
            res.push_back(str);
            return;
        }
        
        if(m>0){
            gen(res, str+")", n, m-1);
        }
        if(n>0){
            gen(res, str+"(", n-1, m+1);
        }
    }
};