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
    void connect(TreeLinkNode *root) {
        // 按层遍历
        if (root == NULL){ return; }
        
        int curLevelCount = 1, nextLevelCount = 0;
        TreeLinkNode* p = root;
        p -> next = NULL;
        queue<TreeLinkNode*> q;
        q.push(p);
        
        while (!q.empty()){
            p = q.front();
            q.pop();

            curLevelCount--;
            
            if (p ->left !=NULL){
                q.push(p -> left);
                q.push(p -> right);
                nextLevelCount += 2;
            }
            
            if (curLevelCount == 0){
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
                p -> next = NULL;
            }else{
                p -> next = q.front();
            }
        }
    }
};