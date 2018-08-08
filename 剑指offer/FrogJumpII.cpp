// 题目描述
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloorII(int number) {
        int sum = 0;
        int r[number+2];
        r[0] = 1;
        r[1] = 1;
        sum = 2;
        for(int i = 2; i<=number; i++){
            r[i] = sum;
            sum += r[i];
        }
        return r[number];
    }
};