class Solution {
public:
    string smallestNumber(string num, long long t) {
        // Step 1: Extract prime factors (2, 3, 5, 7) from t
        int req[8] = {0};
        for (int p : {2, 3, 5, 7}) {
            while (t % p == 0) {
                req[p]++;
                t /= p;
            }
        }
        
        // If t has prime factors > 7, it's impossible
        if (t > 1) return "-1";

        // Helper: Convert factor counts (c2, c3, c5, c7) into minimal digits
        auto get_min_digits = [](int c2, int c3, int c5, int c7) {
            string digits = "";
            for (int i = 0; i < c7; ++i) digits += '7';
            for (int i = 0; i < c5; ++i) digits += '5';
            for (int i = 0; i < c3 / 2; ++i) digits += '9';
            c3 %= 2;
            for (int i = 0; i < c2 / 3; ++i) digits += '8';
            c2 %= 3;

            if (c2 == 1 && c3 == 1) digits += '6';
            else if (c2 == 2 && c3 == 1) { digits += '2'; digits += '6'; }
            else if (c2 == 1 && c3 == 0) digits += '2';
            else if (c2 == 2 && c3 == 0) digits += '4';
            else if (c2 == 0 && c3 == 1) digits += '3';

            sort(digits.begin(), digits.end());
            return digits;
        };

        // Helper: Factorize a single character digit ('1'-'9')
        auto get_factors = [](char ch) {
            int val = ch - '0';
            vector<int> f(8, 0);
            for (int p : {2, 3, 5, 7}) {
                while (val % p == 0) {
                    f[p]++;
                    val /= p;
                }
            }
            return f;
        };

        // Step 2: Check if num itself is valid (zero-free & product divisible by t)
        bool zero_free = (num.find('0') == string::npos);
        if (zero_free) {
            int cur_req[8];
            copy(begin(req), end(req), begin(cur_req));
            for (char ch : num) {
                vector<int> f = get_factors(ch);
                for (int p : {2, 3, 5, 7}) {
                    cur_req[p] = max(0, cur_req[p] - f[p]);
                }
            }
            bool satisfied = true;
            for (int p : {2, 3, 5, 7}) {
                if (cur_req[p] > 0) satisfied = false;
            }
            if (satisfied) return num;
        }

        int n = num.length();
        size_t first_zero = num.find('0');
        // We can diverge at or before the first '0'
        int max_diverge_idx = (first_zero != string::npos) ? first_zero : n - 1;

        // Precompute remaining factor requirements along prefix
        vector<vector<int>> prefix_req(max_diverge_idx + 1, vector<int>(8, 0));
        for (int p : {2, 3, 5, 7}) prefix_req[0][p] = req[p];

        for (int i = 0; i < max_diverge_idx; ++i) {
            vector<int> f = get_factors(num[i]);
            for (int p : {2, 3, 5, 7}) {
                prefix_req[i + 1][p] = max(0, prefix_req[i][p] - f[p]);
            }
        }

        // Step 3: Try to find a valid divergence point of length n
        for (int i = max_diverge_idx; i >= 0; --i) {
            int rem_len = n - 1 - i;
            int cur_digit = num[i] - '0';

            for (int d = cur_digit + 1; d <= 9; ++d) {
                vector<int> f_d = get_factors(d + '0');
                int rem_req[8];
                for (int p : {2, 3, 5, 7}) {
                    rem_req[p] = max(0, prefix_req[i][p] - f_d[p]);
                }

                string needed = get_min_digits(rem_req[2], rem_req[3], rem_req[5], rem_req[7]);
                
                if ((int)needed.length() <= rem_len) {
                    string res = num.substr(0, i);
                    res += to_string(d);
                    res.append(rem_len - needed.length(), '1');
                    res += needed;
                    return res;
                }
            }
        }

        // Step 4: Expand length safely if length n is impossible
        string needed = get_min_digits(req[2], req[3], req[5], req[7]);
        int target_len = max(n + 1, (int)needed.length());

        string res = "";
        res.append(target_len - needed.length(), '1');
        res += needed;
        return res;
    }
};