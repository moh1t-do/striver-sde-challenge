class StockSpanner {
    stack<pair<int,int>> stk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int k = 0;
        while(!stk.empty() && stk.top().first<=price)
        {
            k += stk.top().second+1;
            stk.pop();
        }
        stk.push({price, k});
        return k+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */