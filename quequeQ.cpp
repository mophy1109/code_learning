// 链接：https://www.nowcoder.com/acm/contest/131/A
// 来源：牛客网

// 题目描述 
// ZZT 创造了一个队列 Q。这个队列包含了 N 个元素，队列中的第 i 个元素用 Qi 表示。Q1 表示队头元素，QN 表示队尾元素。队列中的元素是 N 的一个全排列。 

// ZZT 需要在这个队列上执行 P 次操作，操作分两种：
// FIRST X: 将元素 X 移到队头。
// LAST X: 将元素 X 移到队尾。

// 在 P 次操作之后，ZZT 想知道队列中的元素的排列方式，由于他最近很忙，因此需要请你帮他解决这个问题。
// 输入描述:
// 第一行输入一个正整数 N，表示队列的大小。
// 第二行输入 N 个正整数，Q1, Q2, Q3, ... ..., QN，Qi 表示队列中的第 i 个元素。保证这 N 个数是 N 的一个全排列。
// 第三行输入一个正整数 P，表示接下来要进行的操作次数。
// 接下来 P 行，第 i 行输入一个字符串 Si 以及一个正整数 Xi，表示一次操作。
// 1 ≤ N ≤ 105.
// 1 ≤ Qi ≤ N.
// 1 ≤ P ≤  105.
// Si  { “FIRST”, “LAST” }.
// 1 ≤ Xi ≤ 105.
// 输出描述:
// 输出 N 个正整数，表示 P 次操作之后的队列。
// 示例1
// 输入
// 复制
// 4
// 4 2 1 3
// 3
// FIRST 4
// LAST 2
// LAST 1
// 输出
// 复制
// 4 3 2 1

// 备注 ： 这题不知道为什么在本机G++环境输出无误， 在牛客网的clang++3.9环境结果错误。
// 正确答案里全是用C的大佬，服了，告辞

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> Q;
    Q.reserve(N);
    for (int i = 0; i<N; i++){
        int elem;
        cin >> elem;
        Q.push_back(elem);
    }
    int P;
    cin >> P;
    for (int i = 0; i<P; i++){
        string s;
        cin >> s;
        if (s == "FIRST"){
            int x;
            cin >> x;
            Q.erase(find(Q.begin(),Q.end(),x));
            Q.insert(Q.begin(),x);
        }else{
            int x;
            cin >> x;
            Q.erase(find(Q.begin(),Q.end(),x));
            Q.push_back(x);
        }
    }
    for (int i= 0; i<Q.size();i++){
        cout << i;
        if ( i != Q.size()-1){
            cout << " ";
        }
    }
    return 0;
}