// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True
// Example 2:
// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

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
    //solution 1: hash
    bool findTarget1(TreeNode* root, int k) {
        set<int> hash;
        return findval(hash, root, k);
    }

    bool findval(set<int>& hash, TreeNode* root, int k){
        if (root == NULL){
            return false;
        }else if (hash.count(k-root->val) != 0){
            return true;
        }else{
            hash.insert(root -> val);
            return findval(hash, root->left, k)||findval(hash, root->right,k);
        }
    }

    //solution 2: BFS,O(n)时间复杂度，O(n)空间复杂度
    bool findTarget2(TreeNode* root, int k) {
        set<int> hash;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(hash.count(k-temp->val)!=0){
                return true;
            }
            hash.insert(temp->val);
            if (temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            q.pop();
        }
        return false;
    }

    //solution 3: 使用BST的性质，BST的中序遍历是一个递增序列
    //~24ms
    bool findTarget3(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        for(int i = 0, j=result.size()-1;i<j;){
            if(result[i]+result[j] == k){
                return true;
            }else if(result[i]+result[j] < k){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }

    void inorder(TreeNode* root, vector<int>& res){
        if(root != NULL){
            inorder(root->left);
            res.push_back(root->val);
            inorder(root->right);
        }
    }
};