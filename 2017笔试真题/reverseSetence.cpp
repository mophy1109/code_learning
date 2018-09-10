// 题目描述

// 给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。

// 比如：

// （1） “hello xiao mi”-> “mi xiao hello”

// 输入
// 输入数据有多组，每组占一行，包含一个句子(句子长度小于1000个字符)

// 样例输入
// hello xiao mi

// 输出
// 对于每个测试示例，要求输出句子中单词反转后形成的句子

// 样例输出
// mi xiao hello

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> result;
    string str;
    while(cin >> str) {
        result.push_back(str);
    }
    for (auto it = result.rbegin(); it < result.rend(); it++) {
        cout << *it;
        if (it < result.rend() - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 1;
}