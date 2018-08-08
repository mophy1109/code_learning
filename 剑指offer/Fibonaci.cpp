// 题目描述
// 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
// n<=39

class Solution {
public:
    //solution 1: 常规方法，使用O(n) 的额外空间，计算n次加法
    int Fibonacci1(int n) {
        int fib[40];
        fib[0] = 0;
        fib[1] = 1;
        for(int i = 2; i<=n; i++){
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }

    //solution 2: 一个计算斐波那契数列等f[n] 依赖于 f[n-1]  f[n-2]的好方法，额外空间O(1)
    int Fibonacci1(int n) {
        if (n < 1) return 0;
        int i = 1;//第一项
        int j = 1;//第二项
        while(n--){
            j = j + i;
            i = j - i;
        }
        return i;
    }
};