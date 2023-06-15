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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode *p, *q;
        p = q = head;
        
        // two pointer
        while(p && p->next)
        {
            p = p->next->next;
            q = q->next;
            if (p == q)
            {
                q = head;
                while(p != q)
                {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};