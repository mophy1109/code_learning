// 链接：https://www.nowcoder.com/acm/contest/157/E
// 来源：牛客网

// 题目描述
// 有一只可爱的老青蛙，在路的另一端发现了一个黑的东西，想过去一探究竟。于是便开始踏上了旅途
// 一直这个小路上有很多的隧道，从隧道的a进入，会从b出来，但是隧道不可以反向走。
// 这只青蛙因为太老了，所以很懒，现在想请你帮帮慢，问他最少需要几步才可以到达对面。
// 将小径看作一条数轴，青蛙初始在0上，这只青蛙可以向前跳也可以向后跳，但每次只能跳一格，每跳一格记作一步，从隧道进到隧道出算做一步。
// 输入描述:
// 第一行两个数m,n；表示黑色物品在数轴m点上，数轴上总共有n个隧道
// 接下来n行，每行a，b两个数，表示从a进会从b出

// 10 <= m,n <= 233

// 0<a,b<=m
// 输出描述:
// 一个数ans表示最小步数
// 示例1
// 输入
// 复制
// 16 4
// 2 10
// 8 15
// 12 5
// 13 6
// 输出
// 复制
// 7
// 说明
// 0-->1-->2-->10-->9-->8-->15-->16


#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

//DP
int main()
{
    int m, n;
    cin >> m >> n;

    int road[250][250];

    road[0][0] = 0;
    // memset(road, , sizeof(road));

    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << road[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            road[i][j] = abs(i - j);
        }
    } //初始化距离

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        road[a][b] = 1;
    }

    //注意ijk的顺序

    for (int k = 0; k <= m; k++) {
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= m; j++) {
                road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
            }
        }
    }

    cout << road[0][m] << endl;
    return 0;
}

