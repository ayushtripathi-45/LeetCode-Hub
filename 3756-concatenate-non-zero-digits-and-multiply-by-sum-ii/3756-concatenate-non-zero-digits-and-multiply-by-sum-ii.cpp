class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long mod = 1e9 + 7;
        long long pow[100001];

        pow[0] = 1;
        for (int i = 1; i < 100001; i++) {
            pow[i] = (pow[i - 1] * 10) % mod;
        }

        vector<long long> pref(n + 1, 0);
        vector<long long> numbs(n + 1, 0);
        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digi = s[i] - '0';
            pref[i + 1] = pref[i] + digi;
            numbs[i + 1] = digi ? (numbs[i] * 10 + digi) % mod : numbs[i];
            len[i + 1] = len[i] + (digi > 0);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int lensubstr = len[r] - len[l];

            long long multi = (numbs[l] * pow[lensubstr]) % mod;
            long long num = (numbs[r] - multi + mod) % mod;

            long long currsum = pref[r] - pref[l];

            long long prod = (num * currsum) % mod;

            ans.push_back(prod);
        }

        return ans;
    }
};