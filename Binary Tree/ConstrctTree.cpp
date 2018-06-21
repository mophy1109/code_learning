// 从中序与后序遍历序列构造二叉树
// 根据一棵树的中序遍历与后序遍历构造二叉树。

// 注意:
// 你可以假设树中没有重复的元素。

// 例如，给出

// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7


// Definition for a binary tree node.

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return prepostbuild(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* inpostbuild(vector<int>& inorder,int i_in,int j_in,vector<int>& postorder,int i_post,int j_post)
    {
        //由中序遍历和后序遍历构造二叉树

        //注意遍历传入参数是前序遍历起点下标 和 终点下标+1

        if (i_in >= j_in || i_post >= j_post)
            return NULL;
        
        int sub_root = postorder[j_post - 1];
        
        auto f = find(inorder.begin() + i_in, inorder.begin() + j_in, sub_root); // 返回R的绝对下标
        
        int dis = f - inorder.begin() - i_in;// 相对下标/偏移
        
        TreeNode* root = new TreeNode(sub_root);
        
        root -> left = inpostbuild(inorder, i_in , i_in + dis, postorder, i_post, i_post + dis);// 左子树的中序遍历、后序遍历。即 XXXXXX …… R | …… XXXXX 的左半部分
        
        root -> right = inpostbuild(inorder, i_in + dis + 1, j_in, postorder, i_post + dis, j_post - 1);
        
        return root;
    }
    
    TreeNode* prepostbuild(vector<int>& preorder,int i_pre,int j_pre, vector<int>& inorder,int i_in,int j_in)
    {
        //由前序遍历和后序遍历构造二叉树
        if (i_pre >= j_pre || i_in >= j_in)
            return NULL;
        
        int sub_root = preorder[i_pre];
        
        auto f = find(inorder.begin() + i_in, inorder.begin() + j_in, sub_root); // 返回下标
        
        int dis = f - inorder.begin() - i_in; //在中序遍历中找到root位置

        TreeNode* root = new TreeNode(sub_root);
        
        root -> left = prepostbuild(preorder, i_pre + 1 , i_pre + dis + 1, inorder, i_in, i_in + dis);// 左子树的前序遍历、中序遍历。即 R …… XXXXXX | …… XXXXX 的左半部分
        
        root -> right = prepostbuild(preorder, i_pre + dis + 1, j_pre, inorder, i_in + dis + 1, j_in);
        
        return root;
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}