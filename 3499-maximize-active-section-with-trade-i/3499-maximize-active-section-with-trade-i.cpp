class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int initial_ones = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                initial_ones++;
            }
        }
        
        vector<char> types;
        vector<int> counts;
        
        int current_count = 0;
        for (int i = 0; i < n; i++) {
            current_count++;
            
            if (i == n - 1 || s[i] != s[i + 1]) {
                types.push_back(s[i]);
                counts.push_back(current_count);
                current_count = 0;
            }
        }
        
        int max_gain = 0;
        int total_segments = types.size();
        
        for (int i = 1; i < total_segments - 1; i++) {
            if (types[i] == '1') {
               
                int gain = counts[i - 1] + counts[i + 1];
                
                if (gain > max_gain) {
                    max_gain = gain;
                }
            }
        }
       
        return initial_ones + max_gain;
    }
};