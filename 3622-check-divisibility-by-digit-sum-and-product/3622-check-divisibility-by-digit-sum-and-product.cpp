class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 0, b = 1;
        for(int x = n; x > 0; x/= 10){
            int c = x % 10;
            a += c;
            b *= c;
        }
        return n % (a + b) == 0;
    }
};