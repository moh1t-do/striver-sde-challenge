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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        ListNode* p, *q, *n;
        n = new ListNode();
        n->next = head;
        p = head;
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
        }
        len = k%len;
        if (len == 0)
            return head;
        p = q = n;
        while(len--) p = p->next;
        while(p->next)
        {
            p = p->next;
            q = q->next;
        }
        head = q->next;
        p->next = n->next;
        q->next = NULL;
        delete n;
        return head;
    }
};