class Solution {
public:
    
    int getGCD(int a, int b) {
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        
        int min_num = nums[0];
        int max_num = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min_num) {
                min_num = nums[i];
            }
            if (nums[i] > max_num) {
                max_num = nums[i];
            }
        }
       
        return getGCD(max_num, min_num);
    }
};