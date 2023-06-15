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
    ListNode* reverse(ListNode* x)
    {
        ListNode *p, *q, *r;
        q=x;
        p=r=NULL;
        
        while(q)
        {
            p=q->next;
            q->next = r;
            r = q;
            q = p;
        }
        return r;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *p, *q;
        p = q = head;
        
        // two pointers to get the middle node
        while(p && p->next)
        {
            p=p->next->next;
            q=q->next;
        }
        p=head;
        q=reverse(q);
        
        while(p && q)
        {
            if (p->val != q->val)
                return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};