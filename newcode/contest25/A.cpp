// 链接：https://www.nowcoder.com/acm/contest/160/A
// 来源：牛客网

// 题目描述
// 有一个计数器，计数器的初始值为0，每次操作你可以把计数器的值加上a1,a2,...,an中的任意一个整数，操作次数不限（可以为0次），问计数器的值对m取模后有几种可能。
// 输入描述:
// 第一行两个整数n,m
// 接下来一行n个整数表示a1,a2,...,an
// 1≤n≤100
// 1≤m,a1,a2,...,an≤1000000000
// 输出描述:
// 输出一个整数表示答案
// 示例1
// 输入
// 复制
// 3 6
// 6 4 8
// 输出
// 复制
// 3

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int t = m;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        t = gcd(t, a[i]);
    }

    cout << m/t << endl;
    return 0;
}