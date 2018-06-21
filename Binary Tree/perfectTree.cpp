// 每个节点的右向指针
// 给定一个二叉树

// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// };
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

// 初始状态下，所有 next 指针都被设置为 NULL。

// 说明:

// 你只能使用额外常数空间。
// 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
// 你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
// 示例:

// 给定完美二叉树，

//      1
//    /  \
//   2    3
//  / \  / \
// 4  5  6  7
// 调用你的函数后，该完美二叉树变为：

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \  / \
// 4->5->6->7 -> NULL

//-----------变体--------------
// 非完美二叉树的情况


// 给定二叉树，

//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7
// 调用你的函数后，该二叉树变为：

//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL



class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 按层遍历，逐层输出
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
            
            if (p -> left != NULL){
                q.push(p -> left);
                nextLevelCount++;
            }
            
            if (p -> right != NULL){
                q.push(p -> right);
                nextLevelCount++;
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