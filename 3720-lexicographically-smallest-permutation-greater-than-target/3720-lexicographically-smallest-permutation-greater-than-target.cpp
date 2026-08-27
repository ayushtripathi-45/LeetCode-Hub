class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int max_match = 0;
        vector<int> temp_count = count;
        while (max_match < n) {
            int char_idx = target[max_match] - 'a';
            if (temp_count[char_idx] > 0) {
                temp_count[char_idx]--;
                max_match++;
            } else {
                break;
            }
        }
        for (int i = max_match; i >= 0; i--) {
            vector<int> current_count = count;
            for (int j = 0; j < i; j++) {
                current_count[target[j] - 'a']--;
            }

            int target_char = (i < n) ? (target[i] - 'a') : -1;
            for (int c = target_char + 1; c < 26; c++) {
                if (current_count[c] > 0) {
                    string result = target.substr(0, i);
                    result += (char)('a' + c);
                    current_count[c]--;
                    for (int ch = 0; ch < 26; ch++) {
                        while (current_count[ch] > 0) {
                            result += (char)('a' + ch);
                            current_count[ch]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};