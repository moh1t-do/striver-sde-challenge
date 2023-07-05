#include <bits/stdc++.h>
struct Node
{
    Node *link[26];
    int cnt = 0;
    int endWith = 0;

    bool containKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, Node *cur)
    {
        link[ch - 'a'] = cur;
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void increasePrefix()
    {
        cnt++;
    }

    void increaseEnd()
    {
        endWith++;
    }

    void decreasePrefix()
    {
        cnt--;
    }

    void decreaseEnd()
    {
        endWith--;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!cur->containKey(word[i]))
                cur->put(word[i], new Node());
            cur = cur->get(word[i]);
            cur->increasePrefix();
        }
        cur->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (cur->containKey(word[i]))
                cur = cur->get(word[i]);
            else
                return 0;
        }
        return cur->endWith;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (cur->containKey(word[i]))
                cur = cur->get(word[i]);
            else
                return 0;
        }
        return cur->cnt;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (cur->containKey(word[i]))
            {
                cur = cur->get(word[i]);
                cur->decreasePrefix();
            }
        }
        cur->decreaseEnd();
    }
};
