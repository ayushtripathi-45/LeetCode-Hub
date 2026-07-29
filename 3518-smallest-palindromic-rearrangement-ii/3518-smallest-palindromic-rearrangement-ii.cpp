class Solution {
    long long nc(int n, int k, long long max){
        long long res = 1;
        int limit = min(k, n-k);
        for (int i =1 ; i <= limit; ++i){
            res = res * (n-i+1)/i;
            if ( res >= max){
                return max;
            }
        }
        return res;
    }

    long long countArrangements(const vector<int>& count, long long max) {
        int total = 0;
        for (int c : count) total += c;
        long long res = 1;
        for (int freq : count) {
            if (freq == 0) continue;
            res *= nc(total, freq, max);
            if (res >= max) return max;
            total -= freq;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
      long long MAX = 1000005;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> halfCount(26, 0);
        string mid = "";
        for (int i = 0; i < 26; ++i) {
            halfCount[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                mid = string(1, (char)('a' + i));
            }
        }

        if (countArrangements(halfCount, MAX) < k) {
            return "";
        }

        int halfLen = s.length() / 2;
        string left = "";

        for (int pos = 0; pos < halfLen; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (halfCount[i] == 0) continue;

                halfCount[i]--;
                long long arrangements = countArrangements(halfCount, MAX);

                if (arrangements >= k) {
                    left += (char)('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};