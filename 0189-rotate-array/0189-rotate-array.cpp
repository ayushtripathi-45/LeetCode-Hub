class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        vector<int> temp;
        for (int i = 0; i < n - k; i++) {
            temp.push_back(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            nums[i] = nums[n - k + i];
        }
        for (int j = 0; j < temp.size(); j++) {
            nums[k + j] = temp[j];
        }
    }
};