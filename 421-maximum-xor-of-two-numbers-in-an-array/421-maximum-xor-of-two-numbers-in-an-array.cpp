class Node{
    public:
    Node* links[2];
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *cur = root;

        for(int i=31; i>=0; i--){
            int bit = num>>i & 1;
            if (cur->links[bit] == NULL){
                cur->links[bit] = new Node();
            }
            cur = cur->links[bit];
        }
    }

    int maxnum(int num){
        Node *cur = root;

        int mx = 0;
        for(int i=31; i>=0; i--){
            int bit = num>>i & 1;

            if (cur->links[1-bit] == NULL)
            cur = cur->links[bit];
            else{
                mx = mx | (1<<i);
                cur = cur->links[1-bit];
            }
        }
        return mx;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();

        for(int i=0; i<nums.size(); i++)
        t->insert(nums[i]);

        int res = 0;
        for(int i=0; i<nums.size(); i++)
        res = max(res, t->maxnum(nums[i]));

        return res;
    }
};