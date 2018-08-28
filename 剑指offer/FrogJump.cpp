// 题目描述
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

class Solution {
public:
    //solution 1 : 显然，跳跃到n级的种类是前面所有n-1级的所有情形种类之和
    int jumpFloor1(int number) {
        int r[number + 2];
        r[0] = 1;
        r[1] = 1;
        for(int i = 2;i<=number; i++){
            r[i] = r[i-1] + r[i-2];
        }
        return r[number];
    }

    //solution 2：对数据进行整理发现 1, 1, 2, 4, 8, 16……通项公式2^(n-1)
    int jumpFloor2(int number) {
        return (int)pow(2, number-1);
    }
};
