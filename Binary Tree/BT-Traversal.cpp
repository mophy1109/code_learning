// leetcode 二叉树遍历 非递归
// 包括 ： 先序遍历 中序遍历 后序遍历 按层遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        // 先序遍历
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* p = root;
        
        while(p != NULL){
            result.push_back(p->val);
            if (p->right != NULL){
                s.push(p->right);
            }
            if (p->left != NULL){
                p = p->left;
            }else{
                if (s.empty()){
                    break;
                }
                p = s.top();
                s.pop();
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // 中序遍历
        vector<int> result;
        TreeNode *p = root;
        stack<TreeNode*> s;
        while(p != NULL || !s.empty()){
            while(p != NULL){
                s.push(p);
                p = p -> left;
            }
            if(!s.empty()){
                p = s.top();
                result.push_back(p -> val);
                s.pop();
                p = p -> right;
            }
        }
        return result;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // 后序遍历
        TreeNode* p = root;
        TreeNode* pRightChild;
        stack<TreeNode*> s;
        set<TreeNode*> visited;
        vector<int> result;
        
        if (p != NULL){
            s.push(p);
            p = p ->left;
        }else {
            return result;
        }

        while( !s.empty() ) {  
            while( p != NULL && visited.count(p) == 0 ) { /* 注意循环的条件 */  
                s.push( p );  
                p = p ->left;  
            }  
            p = s.top();  
            s.pop();  
            pRightChild = p ->right;  
            if( pRightChild == NULL || visited.count(pRightChild) == 1 ) {  
               result.push_back(p -> val); /* 访问该节点 */  
               visited.insert(p); /* 设置访问标记 */  
            }else /* if( pRightChild != NULL && visited.count(pRightChild) == 0 ) */  
            {
                s.push( p );  
                s.push( pRightChild );  
                p = pRightChild ->left; /* 重新设置当前处理节点为右子树的左孩子 */  
            }
        }
        return result;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        // 按层遍历，逐层输出
        vector<vector<int>> result;
        vector<int> tmp_level;
        if (root == NULL){ return result; }
        
        int curLevelCount = 1, nextLevelCount = 0;
        TreeNode* p = root;
        queue<TreeNode*> q;
        q.push(p);
        
        while (!q.empty()){
            p = q.front();
            q.pop();

            tmp_level.push_back(p -> val);
            curLevelCount--;
            
            if (p -> left != NULL){
                q.push(p -> left);
                nextLevelCount++;
            }
            
            if (p -> right != NULL){
                q.push(p -> right);
                nextLevelCount++;
            }
            
            if (curLevelCount == 0){
                result.push_back(tmp_level);
                tmp_level.clear();
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }
        return result;
    }
};