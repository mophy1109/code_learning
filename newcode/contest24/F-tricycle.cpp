// 链接：https://www.nowcoder.com/acm/contest/157/F
// 来源：牛客网

// 题目描述
// 小k有一个三轮，它最多可以装105大小的东西
// 小k有n种商品，他要准备出摊了
// 每种商品体积为vi，都有105件
// 输出凑成1~m的体积的总方案数
// 输出可能会很大，请对大质数19260817取模
// 输入描述:
// 第一行两个整数n,m，
// 接下来n行，每行一个数代表vi
// 输出描述:
// 一个数ans表示总方案数
// 示例1
// 输入
// 复制
// 2 8
// 1
// 3
// 输出
// 复制
// 17
// 说明
// 从1~m体积的方案数分别为：
// 1
// 1
// 2
// 2
// 2
// 3
// 3
// 3
// 备注:
// 不要忘记取模！！！
// n,m,vi <= 50000

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;

    int options[m + 1]; //初始方案均为0种
    for (int i = 0; i <= m; i++) {
        options[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int vi;
        cin >> vi;

        if (vi > m)
            continue;

        options[vi] = 1;
    }

    for (int j = 1; j <= m; j++) {
        int pre = 0, post = j;

        while (pre <= post) {
            options[j] = (options[j] + options[pre] * options[post]) % 19260817;
            pre++;
            post--;
        }
    }

    int sum = 0;
    for (int i = 0; i <= m; i++) {
        cout << options[i] << ",";
        sum = (sum + options[i]) % 19260817;
    }
    cout <<endl << sum << endl;
    return 0;
}