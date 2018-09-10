// 题目描述
// 有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
// 输入描述:
// 每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
// 输出描述:
// 输出一行表示最大的乘积。

// 示例1
// 输入
// 复制
// 3
// 7 4 7
// 2 50
// 输出
// 复制
// 49

#include <bits/stdc++.h>

using namespace std;

long long funmax[51][51];
long long funmin[51][51];

int main()
{
    int n, k, d;
    cin >> n;
    int a[n + 1];

    memset(funmax, 0, sizeof funmax);
    memset(funmin, 0, sizeof funmin);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> k >> d;

    //funmax[k][pos]表示前pos个学生中选k个的最大结果，funmin表示最小结果
    long long maxval = numeric_limits<long long>::min();
    for (int pos = 1; pos <= n; pos++) {
        funmax[1][pos] = a[pos];
        funmin[1][pos] = a[pos];
        for (int kk = 2; kk <= k; kk++) {
            for (int j = pos - d; j < pos; j++) {
                funmax[kk][pos] =
                    max(funmax[kk][pos], max(funmax[kk - 1][j] * a[pos],
                                             funmin[kk - 1][j] * a[pos]));
                funmin[kk][pos] =
                    min(funmin[kk][pos], min(funmax[kk - 1][j] * a[pos],
                                             funmin[kk - 1][j] * a[pos]));
            }
        }
        maxval = max(maxval, funmax[k][pos]);
    }

    cout << maxval << endl;
    return 0;
}