class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int totalP = 0;

        for(int i = 0; i<n;i++){
            if(i<8){
                totalP += 1;
            }else if (i < 16){
                totalP += 2;
            }else if (i< 24){
                totalP += 3;
            }else {
                totalP += 4;
            }
        }
        return totalP;
    }
};