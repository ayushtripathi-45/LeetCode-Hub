class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];
        unordered_set<int> present;

        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
            present.insert(num);
        }

        vector<int> result;
        for (int i = minVal; i <= maxVal; i++) {
            if (present.find(i) == present.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};