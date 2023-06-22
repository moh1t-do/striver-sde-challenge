#include <bits/stdc++.h>

void insert(stack<int> &stk, int x)
{
    if (stk.empty() || stk.top() < x)
    {
        stk.push(x);
        return;
    }
    int y = stk.top();
    stk.pop();
    insert(stk, x);
    stk.push(y);
}

void sortStack(stack<int> &stk)
{
    // Write your code here
    if (stk.empty())
        return;
    int x = stk.top();
    stk.pop();
    sortStack(stk);
    insert(stk, x);
}