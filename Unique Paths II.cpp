// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

#include <vector>

using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        vector<vector<int>> result(height+1, vector<int>(width+1, 0));
        result[0][1] = 1;
        for (auto i = 1; i<=height; i++){
            for (auto j = 1; j<=width; j++){
                if(obstacleGrid[i-1][j-1] == 0){
                    result[i][j] = result[i-1][j] + result[i][j-1];
                }else{
                    result[i][j] = 0;
                }
            }
        }
        return result[height][width];
    }
};