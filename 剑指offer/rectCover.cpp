// 题目描述
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

class Solution {
public:
    //动态规划，依旧是斐波那契数列。。
    int rectCover(int number) {
        int r[number + 3];
        r[0] = 0;
        r[1] = 1;
        r[2] = 2;
        for (int i = 3; i<=number; i++){
            r[i] = r[i-1] + r[i-2];
        }
        return r[number];
    }

    
};