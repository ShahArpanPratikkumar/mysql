class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int i = 0, j = 0;
        int sum = 0, ans = 0;

        while (j < nums.size()) {
            while (st.count(nums[j])) {
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            st.insert(nums[j]);
            sum += nums[j];
            ans = max(ans, sum);
            j++;
        }

        return ans;
    }
};