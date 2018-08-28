// 链接：https://www.nowcoder.com/acm/contest/160/D
// 来源：牛客网

// 题目描述
// 给出一个长度为n的整数序列a1,a2,...,an，进行m次操作，操作分为两类。
// 操作1：给出l,r,v，将al,al+1,...,ar分别加上v；
// 操作2：给出l,r，询问
// 输入描述:
// 第一行一个整数n
// 接下来一行n个整数表示a1,a2,...,an
// 接下来一行一个整数m
// 接下来m行，每行表示一个操作，操作1表示为1 l r v，操作2表示为2 l r
// 保证1≤n,m,ai,v≤200000；1≤l≤r≤n，v是整数
// 输出描述:
// 对每个操作2，输出一行，表示答案，四舍五入保留一位小数
// 保证答案的绝对值大于0.1，且答案的准确值的小数点后第二位不是4或5
// 数据随机生成（n,m人工指定，其余整数在数据范围内均匀选取），并去除不满足条件的操作2
// 示例1
// 输入
// 复制
// 4
// 1 2 3 4
// 5
// 2 2 4
// 1 1 3 1
// 2 2 4
// 1 2 4 2
// 2 1 3
// 输出
// 复制
// 0.3
// -1.4
// -0.3
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            for (int t = l; t <= r; t++) {
                a[t] += v;
            }
        } else {
            int l, r;
            float sum;
            sum = 0;
            cin >> l >> r;
            for (int t = l; t <= r; t++) {
                sum += sin(a[t]);
            }
            cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
        }
    }
    return 0;
}