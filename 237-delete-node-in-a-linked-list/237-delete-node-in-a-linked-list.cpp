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
    void deleteNode(ListNode* node) {
        // assign value to the next node
        ListNode *q = node;
        q = q->next;
        node->val = q->val;
        node->next = q->next;
        delete q;
    }
};