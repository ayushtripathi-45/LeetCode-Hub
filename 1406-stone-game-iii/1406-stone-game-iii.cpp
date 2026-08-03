class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i] stores max (Player Score - Opponent Score) starting from index i
        // Array size is n + 1 so dp[n] = 0 (base case when no stones left)
        std::vector<int> dp(n + 1, 0);

        // Solve backwards from the last stone to the first
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = INT_MIN;
            int current_take = 0;

            // Try taking 1, 2, or 3 stones
            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_take += stoneValue[i + k - 1]; // Score of stones taken
                
                // Total advantage = (stones taken now) - (opponent's future advantage)
                dp[i] = std::max(dp[i], current_take - dp[i + k]);
            }
        }

        // Check result at index 0 (Alice's starting position)
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};