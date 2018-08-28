// 链接：https://www.nowcoder.com/acm/contest/157/A
// 来源：牛客网

// 题目描述 
// xb有m种石子，每种无限个，Ta想从这些石子中取出n个，并按顺序排列起来，为了好看，相邻的石子不能相同。xb想知道有多少种排列的方法。

// 输入描述:
// 第一行有两个正整数n，m。
// 输出描述:
// 第一行一个整数，表示在m种石子中取出n个的排列方案数模1000000007后的值。

// 示例1
// 输入
// 1 1
// 输出
// 1

// 示例2
// 输入
// 2 3
// 输出
// 6

// 示例3
// 输入
// 3 3
// 输出
// 12

// 备注:
// 对于100%的测试数据：
// 1 ≤ n, m ≤ 1000
// 数据量较大，注意使用更快的输入输出方式。

#include <iostream>

using namespace std;
int main(){
    int m, n;
    cin >> n >> m;
    long long result = m;
    for(int i = 1; i < n; i++){
        result *= (m-1);
        if(result >= 1000000007){
            result %= 1000000007;
        }
    }
    cout << result <<endl;
}