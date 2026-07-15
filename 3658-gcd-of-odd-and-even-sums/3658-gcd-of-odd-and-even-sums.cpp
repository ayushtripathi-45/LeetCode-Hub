class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = (long long)n * n;
        long long sumEven = (long long)n * (n + 1);

        while (sumEven != 0) {
            long long temp = sumEven;
            sumEven = sumOdd % sumEven;
            sumOdd = temp;
        }
        
        return sumOdd;
    }
};