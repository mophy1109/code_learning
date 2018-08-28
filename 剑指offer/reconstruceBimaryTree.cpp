// 题目描述
// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_num = pre.size();
        int vin_num = vin.size();
        return preinbuild(pre, 0, pre_num, vin, 0, vin_num);
    }
    
    TreeNode* preinbuild(vector<int>& pre, int pre_start, int pre_end, vector<int>& vin, int vin_start, int vin_end){
        if(pre_start >= pre_end || vin_start >= vin_end){
            return NULL;
        }
        int root_val = pre[pre_start];
        auto f = find(vin.begin() + vin_start, vin.begin() + vin_end, root_val);
        int dis = f - vin.begin() - vin_start;//偏移量
        
        TreeNode * root = new TreeNode(root_val);
        root -> left = preinbuild(pre, pre_start + 1, pre_start + 1 + dis, vin, vin_start, vin_start + dis);
        root -> right = preinbuild(pre,  pre_start + 1 + dis, pre_end, vin, vin_start + dis + 1, vin_end);
        
        return root;
    }
};