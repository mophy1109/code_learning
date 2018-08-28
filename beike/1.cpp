// 极差之和
// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 给定一个长度为N的序列A1到AN，求所有区间[L，R]（1≤L≤R≤N）的极差之和，其中区间[L，R]的极差定义为AL到AR中的最大值与最小值之差。

// 输入
// 第一行包含一个整数N，1≤N≤105。

// 第二行包含N个空格隔开的整数A1到AN，1≤Ai≤105。

// 输出
// 输出所有区间的极差之和。

// 样例输入
// 5
// 4 1 8 2 5
// 样例输出
// 60

// 温馨提示
// 请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果
// 点击“调试”亦可保存代码
// 编程题可以使用本地编译器，此页面不记录跳出次数

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

void maxminof(const int a[], int st, int end, map<int, int> &min_max)
{
    int max = 0, min = 100001;
    for (int i = st; i <= end; i++) {
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
    }
    min_max[max]++;
    min_max[min]--;
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int a[N];
    int res = 0;
    map<int, int> min_max;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        min_max[a[i]] = 0;
    }

    for (int s = 0; s < N; s++) {
        for (int len = 1; len <= N - s; len++) {
            maxminof(a, s, s + len - 1, min_max);
        }
    }

    for (auto i : min_max) {
        res += i.first * i.second;
    }
    cout << res << endl;
    return 0;
}
