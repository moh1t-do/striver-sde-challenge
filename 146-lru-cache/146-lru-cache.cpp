class LRUCache {
    int cap;
    class dll{
        public:
        int key, val;
        dll *nxt, *pre;
        dll(int k, int v)
        {
            key = k;
            val = v;
            nxt = pre = NULL;
        }
    };
    unordered_map<int,dll*> ump;

public:
    dll *head = new dll(0,0);
    dll *tail = new dll(0,0);

    LRUCache(int capacity) {
        cap = capacity;
        head->nxt = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        auto it = ump.find(key);
        if (it == ump.end()) return -1;

        dll *tmp = create(it->second->key, it->second->val);
        deletedll(it->second);
        ump.erase(key);
        ump[key] = tmp;
        return tmp->val;
    }
    
    void put(int key, int value) {
        auto it = ump.find(key);

        if (it != ump.end())
        {
            deletedll(it->second);
            ump.erase(it->first);
        }

        if (ump.size() == cap)
        {
            dll *tmp = tail->pre;
            int y = tmp->key;
            deletedll(tmp);
            ump.erase(y);
        }

        dll *d = create(key, value);
        ump[key] = d;
    }

    dll* create(int k, int v)
    {
        dll *tmp = new dll(k,v);
        tmp->nxt = head->nxt;
        head->nxt->pre = tmp;
        head->nxt = tmp;
        tmp->pre = head;

        return tmp;
    }

    void deletedll(dll *d)
    {
        dll *tmp = d;
        tmp->pre->nxt = tmp->nxt;
        tmp->nxt->pre = tmp->pre;

        tmp->nxt = tmp->pre = NULL;
        delete tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */