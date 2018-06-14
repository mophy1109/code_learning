// leetcode 对称二叉树
// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3


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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        // 方法1 ： 迭代方式
        TreeNode* l = root -> left;
        TreeNode* r = root -> right;
        stack<TreeNode*> sl, sr;

        vector<int> trvl, trvr;

        while(l!=NULL && r!=NULL){
            if(l -> val != r -> val){
                return false;
            }

            if (l->right != NULL && r -> left != NULL){
                sl.push(l -> right);
                sr.push(r -> left);
            }else if(l ->right != NULL || r ->left != NULL){
                return false;
            }

            if (l->left != NULL && r -> right != NULL){
                l = l -> left;
                r = r -> right;
            }else if (l -> left != NULL || r -> right != NULL){
                return false;
            }else{
                if (sl.empty() && sr.empty()){
                    return true;
                }
                l = sl.top();
                sl.pop();
                r = sr.top();
                sr.pop();
            }
        }
        if (l !=NULL || r!=NULL){
            return false;
        }
        else{
            return true;
        }
    }

    bool isSymmetric2(TreeNode* root) {
        //方法2 ： 递归
        if (root == NULL) return true;
        if (root -> left == NULL && root -> right == NULL) return true;

        TreeNode* l = root -> left;
        TreeNode* r = root -> right;

        return treesAreSymmetric(l, r);
    }

    bool treesAreSymmetric(TreeNode* left, TreeNode* right){
        if(left == NULL ^ right == NULL){
            return false;
        }else if (left == NULL && right == NULL){
            return true;
        }else if (left -> left == NULL && left -> right == NULL && right -> left == NULL && right ->right == NULL ){
            return (left -> val == right -> val);
        }else{
            return (left -> val == right -> val 
            && treesAreSymmetric(left -> left, right -> right)
            && treesAreSymmetric(left -> right, right -> left));
        }
    }
};