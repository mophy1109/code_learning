// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
#include <string.h>

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i<=n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[i-1-j]*dp[j];
            }
        }
        return dp[n];
    }
};