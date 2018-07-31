// 题目描述

// 继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，然后使用对应的大写字母代替

// （"ZERO", "ONE", "TWO", "THREE", "FOUR",

// "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），

// 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。

// 输入
// 第一行是一个整数T（1<=T<=100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。

// 样例输入
// 4

// EIGHT

// ZEROTWOONE

// OHWETENRTEO

// OHEWTIEGTHENRTEO

// 输出
// 输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。

// 样例输出
// 0

// 234

// 345

// 0345

// 时间限制
// C/C++语言：1000MS其它语言：3000MS
// 内存限制
// C/C++语言：65536KB其它语言：589824KB

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //0~9
        int result[10];
        //使用字符：Z 0，O 1，W 2，H 3， U 4， F 5， X 6，S 7， G 8， I 9
        //处理层次：02468最优先，1357其次，9最低
        int b[26];
        memset(b, 0, sizeof(b));
        for (char c: s) {
            b[c-'A']++;
        }

        a[0] = b['Z'-'A'];
        a[2] = b['W'-'A'];
        a[4] = b['U' -'A'];
        a[6] = b['X'-'A'];
        a[8] = b['G'-'A'];
        a[1] = b['O'-'A']-a[0]-a[2]-a[4];
        a[3] = b['H'-'A']-a[8];
        a[5] = b['F'-'A']-a[4];
        a[7] = b['S'-'A']-a[6];
        a[9] = b['I'-'A']-a[6]-a[8]-a[5];

        for(auto ii = 0; ii<10;ii++){
            result[ii] = a[(ii+8)%10];
        }
        for(int jj = 0; jj<10; jj++){
            if(result[jj] != 0){
                for (int t = 0; t< result[jj]; t++){
                    cout << jj;
                }
            }
        }
        cout << endl;
    }
}