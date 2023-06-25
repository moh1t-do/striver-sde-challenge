/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *p = head;

        // case to handle empty list
        if (!p) return p;

        // add copy nodes next to original nodes
        while(p)
        {
            Node *t = new Node(p->val);
            t->next = p->next;
            p->next = t;
            p = t->next;
        }

        // assign copy nodes random 
        p = head;
        while(p)
        {
            Node *t = p->random;

            // case to handle if random pointer points to NULL
            if (t) t = t->next;
            p->next->random = t;
            p = p->next->next;
        }

        // undo the changes
        Node *h, *q;
        h = q = head->next;
        p = head;
        while(p && q)
        {
            p->next = q->next;
            p = p->next;

            // case to handle end of the list
            if (p)
            q->next = p->next;
            q = q->next;
        }

        return h;
    }
};