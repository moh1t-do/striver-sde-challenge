class Solution {
public:
    void solve(int n, int row, vector<string> &board, vector<vector<string>> &ans, vector<bool> &vert, vector<bool> &right, vector<bool> &left)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++)
        {
            if (!vert[col] && !right[row+col] && !left[n-1+col-row])
            {
            board[row][col] = 'Q';
            vert[col] = right[row+col] = left[n-1+col-row] = true;
            solve(n,row+1, board, ans, vert, right, left);
            board[row][col] = '.';
            vert[col] = right[row+col] = left[n-1+col-row] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(auto &i: board)
            i=s;
        vector<bool> vert(n,false), right(2*n-1, false), left(2*n-1, false);
        solve(n,0,board,ans, vert, right, left);
        return ans;
    }
};