// Given a triangle, find the minimum path sum from top to bottom. 
// Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:

    //non-DP solution, top-down
    int minimumTotal(vector<vector<int>>& triangle) {
        int d = triangle.size();
        for (int i = 1; i<d; i++){
            for (int j = 0; j<=i; j++){
                if(j == 0){
                    triangle[i][j] += triangle[i-1][j];
                    // cout << "triangle" << i << ',' << j << "=" << triangle[i][j];
                }else if(j == i){
                    triangle[i][j] += triangle[i-1][j-1];
                    // cout << "triangle" << i << ',' << j << "=" << triangle[i][j];
                }else{
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                    // cout << "triangle" << i << ',' << j << "=" << triangle[i][j];
                }
            }
        }
        return *min_element(triangle[d-1].begin(), triangle[d-1].end());
    }

    //DP-solution bottom-up
    int minimumTotal2(vector<vector<int>>& triangle) {
        int d = triangle.size();
        vector<vector<int>> minPath(triangle);
        for(int i = d-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                minPath[i][j] += min(minPath[i+1][j], minPath[i+1][j+1]);
            }
        }
        return minPath[0][0];
    }
};