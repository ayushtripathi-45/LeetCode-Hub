class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int halfLen = n / 2;

        string leftHalf = s.substr(0, halfLen);

        sort(leftHalf.begin(), leftHalf.end());

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (n % 2 != 0) {
            return leftHalf + s[halfLen] + rightHalf;
        } else {
            return leftHalf + rightHalf;
        }
    }
};