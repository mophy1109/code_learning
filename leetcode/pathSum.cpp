// leetcode 路径总和
// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

// 说明: 叶子节点是指没有子节点的节点。

// 示例: 
// 给定如下二叉树，以及目标和 sum = 22，

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 迭代方法 ： 使用先序遍历，访问根、和树杈节点时将值加到子节点
        stack<TreeNode*> s;
        TreeNode* p = root;
        
        while(p != NULL){
            if (p->right != NULL){
                p -> right -> val += p -> val;
                s.push(p->right);
            }
            if (p->left != NULL){
                p -> left -> val += p -> val;
                p = p->left;
            }else{
                if (p->right == NULL){
                    if (p -> val == sum){
                        return true;
                    }
                }
                if (s.empty()){
                    break;
                }
                p = s.top();
                s.pop();
            }
        }
        return false;
    }
};