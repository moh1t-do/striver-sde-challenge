class MyStack {
private:
    queue<int> qu;
public:
    MyStack() {
    }
    
    void push(int x) {
        int sz = qu.size();
        qu.push(x);
        for(int i=0; i<sz; i++)
        {
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int x = qu.front();
        qu.pop();
        return x;
    }
    
    int top() {
        int x = qu.front();
        return x;
    }
    
    bool empty() {
        return (qu.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */