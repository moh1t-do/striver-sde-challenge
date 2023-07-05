#include <bits/stdc++.h>
class Node
{
public:
    Node *link[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return link[ch - 'a'] != NULL;
    }

    void put(char ch, Node *n)
    {
        link[ch - 'a'] = n;
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
};

class Trie : public Node
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &s)
    {
        Node *cur = root;
        for (int i = 0; i < s.length(); i++)
        {
            if (!cur->containsKey(s[i]))
                cur->put(s[i], new Node);

            cur = cur->get(s[i]);
        }
        cur->setEnd();
    }

    void get(string &s, string &r)
    {
        Node *cur = root;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            cur = cur->get(s[i]);
            if (!cur->flag)
                return;
        }

        if (s.size() > r.size())
            r = s;
        else if (r.size() == s.size() && s < r)
            r = s;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie *trie = new Trie();

    for (int i = 0; i < n; i++)
        trie->insert(a[i]);
    string res = "";

    for (int i = 0; i < n; i++)
    {
        if (a[i].size() >= res.size())
            trie->get(a[i], res);
    }

    return (res.size() == 0) ? "None" : res;
}