class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;

        for (size_t i = 1; i < nums.size(); ++i) {
            for (int missing = nums[i - 1] + 1; missing < nums[i]; ++missing) {
                result.push_back(missing);
            }
        }

        return result;
    }
};