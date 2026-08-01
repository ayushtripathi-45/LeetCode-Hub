class Solution {
public:
    int getMaxScoreDiff(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        }
        int pickLeft = nums[i] - getMaxScoreDiff(nums, i + 1, j);
        int pickRight = nums[j] - getMaxScoreDiff(nums, i, j - 1);
        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return getMaxScoreDiff(nums, 0, nums.size() - 1) >= 0;
    }
};