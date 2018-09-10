// 因数
// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 给出一个正整数n，求10^18以内含有n个因数的最小的正整数是多少？

// 输入
// 输入仅包含一个正整数n，表示因数的数量(1<=n<=1000)。

// 输出
// 对于每组数据输出一行，仅有一个数字，即小于等于10^18中含有n个因数的最小的正整数。

// 样例输入
// 4
// 样例输出
// 6

#include <bits/stdc++.h>

using namespace std;

void prim(int m, int n = 2, map<int, int>& primes)
{
    if (m >= n) {
        while (m % n)
            n++;
        m /= n;
        prim(m, n);
        primes[n]++;
        // cout << n << endl;
    }
}

int main(){

}