// 链接：https://www.nowcoder.com/acm/contest/157/C
// 来源：牛客网

// 题目描述
//     PH试纸，是一种检测酸碱度的试纸，试纸红色为酸性，蓝色为碱性。
//     HtBest有一个PH试纸，试纸被分成了n段，每一段都可以被染色成红色或者蓝色，WHZ在试纸的每一段上都染为一种颜色，HtBest有m个询问，对于每个询问，Ta想知道某种颜色第qi次在什么地方出现。

// 输入描述:
// 第一行有两个正整数n，m。
// 第二行有n个字母(‘R’或’B’)，每个第i个字母表示PH试纸第i段的颜色。
// 接下来m行，第i行有一个大写字母 ci(‘R’或’B’)和一个正整数qi ，用空格隔开，表示查询颜色ci 第qi 次出现的位置。
// 输出描述:
// 共m行，第i行一个整数，表示查询结果，若颜色ci出现次数少于qi次，则输出-1，否则输出颜色qi第ci次出现的位置。
// 示例1
// 输入
// 复制
// 2 2
// RB
// R 1
// B 1
// 输出
// 复制
// 1
// 2
// 示例2
// 输入
// 复制
// 2 2
// BB
// R 1
// B 2
// 输出
// 复制
// -1
// 2
// 示例3
// 输入
// 复制
// 3 3
// BRB
// B 1
// B 2
// R 1
// 输出
// 复制
// 1
// 3
// 2
// 备注:
// 对于100%的测试数据：
// 1 ≤ n, m ≤ 1000000
// 所有输入数据不超过1000000。
// 数据量较大，注意使用更快的输入输出方式。

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int Red[n];  //R序列
    int Blue[n]; //B序列

    for (int i = 0; i < n; i++) {
        Red[i] = Blue[i] = -1;
    }

    int idR, idB = 0;
    for (int i = 1; i <= n; i++) {
        char color;
        cin >> color;
        if (color == 'R') {
            Red[idR] = i;
            idR++;
        } else {
            Blue[idB] = i;
            idB++;
        }
    }

    for (int i = 0; i < m; i++) {
        char col;
        int t;
        cin >> col;
        cin >> t;
        if (col == 'R')
            cout << Red[t - 1] << endl;
        else
            cout << Blue[t - 1] << endl;
    }

    return 0;
}