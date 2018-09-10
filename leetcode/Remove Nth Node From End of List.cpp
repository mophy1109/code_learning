// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* p = head;
        
        int i = 0;
        for(; i<=n && end != NULL; i++){
            end = end -> next;
        }
        
        if (i == n){
            //delete the first element
            return p->next;
        }else if (i < n) return NULL;
        
        while(end != NULL){
            p = p->next;
            end = end ->next;
        }

        delete p->next;
        
        p->next = p->next->next;
        return head;
    }
};