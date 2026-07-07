class Solution {
public:
    long long sumAndMultiply(int n) {
        if ( n == 0 ) {
            return 0;
        }

        long long x = 0;
        long long sum = 0;
        
        while(n>0){
            int a = n % 10;

            if(a != 0){
                x = x * 10 + a;
                sum += a;
            }
            n /= 10;
        }
        long long y = 0;
        while ( x > 0 ){
            y = y * 10 + ( x % 10);
            x /= 10;
        }
        return y * sum;
    }
};