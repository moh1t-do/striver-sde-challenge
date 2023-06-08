/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        
        queue<Node*> qu;
        qu.push(root);
        
        while(!qu.empty())
        {
            int sz = qu.size();
            for(int i=0; i<sz; i++)
            {
                Node *rt = qu.front();
                qu.pop();
                
                if(rt->left)
                    qu.push(rt->left);
                if(rt->right)
                    qu.push(rt->right);
                
                if (i == sz-1)
                    rt->next = NULL;
                else
                    rt->next = qu.front();
            }
        }
        return root;
    }
};