class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while ( l < r ){
            int c_sum = numbers[l] + numbers[r];

            if(c_sum == target){
                return { l + 1, r + 1};
            }
            else if(c_sum > target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};