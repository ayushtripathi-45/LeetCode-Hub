class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        for(int x = n; x > 0; x/= 10){
            int c = x % 10;
            sum += c;
            prod *= c;
        }
        return n % (sum + prod) == 0;
    }
};