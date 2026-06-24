class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = k - 1; 
        
        int min_diff = INT_MAX;

        while (r < nums.size()) {
            int current_diff = nums[r] - nums[l];
            min_diff = min(min_diff, current_diff);

            l++;
            r++;
        }
        
        return min_diff;
    }
};