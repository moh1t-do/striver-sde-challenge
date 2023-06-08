/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        // three pointer
        ListNode *p, *q, *r;
        p = r = NULL;
        q = head;
        while(q)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};