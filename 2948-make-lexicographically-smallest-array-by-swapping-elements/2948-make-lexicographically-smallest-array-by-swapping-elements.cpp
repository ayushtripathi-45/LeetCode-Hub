class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<std::pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        // Sort pairs by value
        std::sort(sorted_nums.begin(), sorted_nums.end());
        
        std::vector<int> result(n);
        int i = 0;
        
        while (i < n) {
            int j = i;
            std::vector<int> indices;
            
            // Find all connected elements in the current group
            while (j < n) {
                if (j > i && sorted_nums[j].first - sorted_nums[j - 1].first > limit) {
                    break;
                }
                indices.push_back(sorted_nums[j].second);
                j++;
            }
            
            // Sort original indices to place smallest values in leftmost positions
            std::sort(indices.begin(), indices.end());
            
            // Place values back into the result array
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = sorted_nums[i + k].first;
            }
            
            i = j;
        }
        
        return result;
    }
};