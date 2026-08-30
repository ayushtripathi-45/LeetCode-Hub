class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int minIdx = 0;
        int maxIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int first = min(minIdx, maxIdx);
        int second = max(minIdx, maxIdx);
        
        int option1 = second + 1;                 
        int option2 = n - first;                   
        int option3 = (first + 1) + (n - second);  
        return min({option1, option2, option3});
    }
};