class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};

        for ( int i = 0; i< word.length(); i++){
            freq[word[i] - 'a']++;
        }
        int totalP = 0;
        for(int i = 0; i<26; i++){
            int maxI = -1;
            int maxFreq = 0;

            for(int j = 0; j<26;j++){
                if(freq[j] > maxFreq){
                    maxFreq = freq[j];
                    maxI = j;
                }
            }
            if (maxFreq == 0){
                break;
            }
            freq[maxI] = 0;

            int pushesPerChar = (i / 8) + 1;
            totalP += maxFreq * pushesPerChar;
        }
        return totalP;
    }
};