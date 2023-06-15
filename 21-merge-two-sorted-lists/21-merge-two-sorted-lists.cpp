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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p, *q, *t, *head;
        t = NULL;
        p = list1;
        q = list2;
        if (!p || !q)
        {
            if (p) return p;
            else return q;
        }
        
        if (p->val <= q->val) head = p;
        else head = q;
        
        while(p && q)
        {
            while(p && p->val <= q->val)
            {
                t = p;
                p = p->next;
            }
            if (t)
                t->next = q;
            if (!p)
                break;
            
            while(q && q->val < p->val)
            {
                t = q;
                q = q->next;
            }
            t->next = p;
        }
        
        return head;
    }
};