class Solution {
public:
        int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> dp;

        pair<int,int>solve(int row, int col, vector<string>& board){
            if(row<0||col<0){
                return {-1,0};
            }
            if(board[row][col]=='X'){
                return {-1,0};
            }
            if(row == 0 && col == 0){
                return {0,1};
            }
            if(dp[row][col].first != -2){
                return dp[row][col];
            }
            pair<int,int> up = solve(row-1, col,board);
            pair<int,int> left = solve(row, col-1, board);
            pair<int,int> diag = solve(row-1, col-1, board);

            int maxi = max(up.first, max(left.first, diag.first));

            if(maxi == -1){
                return dp[row][col] = {-1,0};
            }

            int paths = 0;

            if(up.first == maxi){
                paths = (paths + up.second) % MOD;
            }
            if(left.first == maxi){
                paths = (paths + left.second) % MOD;
            }
            if(diag.first == maxi){
                paths = (paths + diag.second) % MOD;
            }

            int value = 0;
            if(board[row][col] >= '1' && board[row][col] <= '9'){
                value = board[row][col] - '0';

            }
            return dp[row][col] = {maxi + value, paths};
        }
        vector<int> pathsWithMaxScore(vector<string>& board) {
            int n = board.size();
            dp.assign(n, vector<pair<int,int>>(n, {-2,-2}));
            pair<int,int> ans = solve(n-1, n-1, board);

            if(ans.first == -1){
                return {0,0};
            }

            return {ans.first, ans.second};
    }
};