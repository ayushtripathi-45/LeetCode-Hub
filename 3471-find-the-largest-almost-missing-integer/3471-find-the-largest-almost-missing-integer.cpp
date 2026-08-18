class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> subarrayCount;
        for (int i = 0; i <= n - k; i++) {
            std::unordered_set<int> uniqueInSubarray;
            
            for (int j = i; j < i + k; j++) {
                uniqueInSubarray.insert(nums[j]);
            }
            
            for (int num : uniqueInSubarray) {
                subarrayCount[num]++;
            }
        }
        int maxVal = -1;
        for (auto& [num, count] : subarrayCount) {
            if (count == 1) {
                maxVal = std::max(maxVal, num);
            }
        }

        return maxVal;
    }
};