//二进制问题

#include <iostream>

using namespace std;

class Solution {
public:
    //1、用一条语句判断一个整数是不是2的整数次方
    //思路：如果一个数是2的整数次方，那么它的二进制表示有且仅有1位是1
    bool isPowOfTwo(int num)
    {
        return (num == 0) ? false : (num & (num - 1)) == 0;
    }

    //2、输入两个数m和n，计算需要改变m的二进制表示中的多少位才能得到n。
    //思路：将m,n进行异或运算，对结果计算1的个数即可
    int changeBin(int m, int n)
    {
        int count = 0;
        m = m ^ n;
        while (m != 0) {
            m = m & (m - 1);
            count++;
        }
        return count;
    }
};

int main()
{
    int m, n;

    // test isPowOfTwo
    // while (cin >> n)
    //     (Solution().isPowOfTwo(n)) ? cout << "yes" << endl
    //                                : cout << "no" << endl;

    // test changeBin
    while (cin >> m >> n) {
        cout << Solution().changeBin(m,n) << endl;
    }
}