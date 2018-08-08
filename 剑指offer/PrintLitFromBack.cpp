// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:

    //solution 1: reverse the list
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if (head == NULL) return result;
        
        ListNode *p = NULL;
        
        while(head != NULL){
            ListNode* ne = head->next;
            head->next = p;
            p = head;
            head = ne;
        }
        
        while(p != NULL){
            result.push_back(p->val);
            p= p -> next;
        }
        return result;
    }

    //solution 2: use a stack
    vector<int> printListFromTailToHead2(ListNode* head) {
        vector<int> result;
        stack<int> s;
        while(head != NULL){
            s.push(head->val);
            head = head ->next;
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};