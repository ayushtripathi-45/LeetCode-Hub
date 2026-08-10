class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] will store whether the player whose turn it is with 'i' stones will win.
        vector<bool> dp(n + 1, false);

        // Build up the DP table from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Try removing all possible square numbers: 1*1, 2*2, 3*3, ...
            for (int k = 1; k * k <= i; ++k) {
                // If removing k*k stones leaves Bob in a losing position (false),
                // then Alice wins from this state.
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // No need to check more moves for state 'i'
                }
            }
        }

        return dp[n];
    }
};