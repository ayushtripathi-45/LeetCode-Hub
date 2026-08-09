class Solution {
public:
    int memo[101][101];
    int suffixSum[101];
    int n;

    int dp(int i, int M) {
        if (i >= n) return 0;
        if (i + 2 * M >= n) return suffixSum[i];

        if (memo[i][M] != 0) return memo[i][M];

        int maxStones = 0;
        for (int X = 1; X <= 2 * M; X++) {
            int opponentScore = dp(i + X, max(M, X));
            int currentScore = suffixSum[i] - opponentScore;
            maxStones = max(maxStones, currentScore);
        }

        return memo[i][M] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        for (int i = 0; i <= n; i++) {
            suffixSum[i] = 0;
            for (int j = 0; j <= n; j++) {
                memo[i][j] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        return dp(0, 1);
    }
};