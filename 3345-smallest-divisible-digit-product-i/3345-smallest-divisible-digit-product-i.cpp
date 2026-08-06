class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int pro =1;
            for(int i =  n; i>0;i /= 10){
                pro *= (i%10);
            }
            if(pro % t == 0){
                return n;
            }

            n++;
        }
    }
};