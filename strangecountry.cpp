// 计蒜客 奇怪的国家

// 有一个奇怪的国家，里面的国民对于事情的态度永远只有两面。
// 当两个人遇到一起讨论一个事情的时候——两个持赞同观点的人
// 遇到一起后会对这个事情都继续赞同；一个持赞同观点的人遇
// 到一个持不赞同观点的人的时候，两人都会不再继续赞同；两
// 个持不赞同观点的人遇到一起讨论后反而会对这个事情开始赞同。

#include <cstring>
#include <iostream>

using namespace std;
int main()
{

    char s[50], t[50], res[50];
    cin >> s;
    cin >> t;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == t[i])
            res[i] = '1';
        else
            res[i] = '0';
    }
    for (int i = 0; i < strlen(res); i++) {
        cout << res[i];
    }
    return 1;
}