// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

// Definition for singly-linked list.

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *tail = head;
        ListNode *mid = head;
        
        while (tail->next != NULL && tail->next->next != NULL) {
            mid = mid->next;
            tail = tail->next->next;
        }

        mid = reverseList(mid->next);
        while (mid != NULL) {
            if (mid->val != head->val) {
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *p = NULL;
        ListNode *i = NULL;
        while (head != NULL) {
            i = head->next;
            head->next = p;
            p = head;
            head = i;
        }
        return p;
    }
};