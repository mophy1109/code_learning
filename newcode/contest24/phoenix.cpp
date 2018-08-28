// 链接：https://www.nowcoder.com/acm/contest/157/B
// 来源：牛客网

// 题目描述 
//     凤凰于飞，翙翙其羽，亦集爰止。

//                                         ——《诗经·卷阿》
//     传说，凤凰是百鸟之王。有一天，凤凰要召开百鸟大会，百鸟国是一个由n个节点组成的树，每个节点有一只鸟，开会的节点定在1号节点。每只鸟可以花费1s通过一条边，由于每根树枝(边)的载重有限，只允许一只鸟同时通过。作为会议的策划师，HtBest想知道百鸟国的所有鸟在1点集合最少需要多少秒。


// 输入描述:
// 第一行有一个正整数n，表示百鸟国节点个数。
// 接下来n-1行，第i行两个正整数ai,bi用空格隔开，表示树上节点ai,bi之间有一条边。
// 输出描述:
// 第一行一个整数，表示集合最少需要的时间。
// 示例1
// 输入
// 复制
// 3
// 1 2
// 2 3
// 输出
// 复制
// 2
// 示例2
// 输入
// 复制
// 3
// 1 2
// 1 3
// 输出
// 复制
// 1
// 示例3
// 输入
// 复制
// 4
// 1 2
// 2 3
// 2 4
// 输出
// 复制
// 3
// 备注:
// 对于100%的测试数据：
// 1 ≤ n ≤ 1000000
// 数据量较大，注意使用更快的输入输出方式。

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    public:
    int val;
    vector<TreeNode*> children;
    TreeNode *next;

    TreeNode(int x): val(x), children(NULL), next(NULL){}
};

int main(){
    int n;
    cin >> n;
    TreeNode* root = new TreeNode(1);
    TreeNode* p = root;
    for (int i = 1; i<n; i++){
        int node1, node2;
        TreeNode t = 
    }
}

