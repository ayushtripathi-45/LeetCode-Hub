class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> last_pos(m, -1);

        int ptr = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last_pos[j] = ptr;
                ptr--; 
            }
        }

        vector<int> ans;
        bool changed = false; 
        int j = 0; 

        for (int i = 0; i < n && j < m; i++) {
            bool is_match = (word1[i] == word2[j]);
            
            bool can_finish_rest = (j == m - 1) || (last_pos[j + 1] > i);

            if (is_match) {
                ans.push_back(i);
                j++;
            } else if (!changed && can_finish_rest) {
                
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        if (ans.size() == m) {
            return ans;
        }
        
        return {};
    }
};