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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector < int > ans(queries.size(), 0);
        vector < pair < int, pair < int, int >>> offlineQueries;
        sort(nums.begin(), nums.end());
        int index = 0;
        for (auto & it: queries) {
            offlineQueries.push_back({it[1],{it[0],index++}});
        }

        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        int n = nums.size();
        Trie trie;
        
        for (auto & it: offlineQueries) {
            while (i < n && nums[i] <= it.first) {
            trie.insert(nums[i]);
            i++;
        }
        if (i != 0) ans[it.second.second] = trie.maxnum(it.second.first);
        else ans[it.second.second] = -1;
        }
        return ans;
    }
};