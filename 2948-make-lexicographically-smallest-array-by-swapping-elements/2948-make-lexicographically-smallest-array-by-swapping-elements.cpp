class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Pair elements with their original indices
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }
        
        // Sort pairs primarily by value
        sort(pairs.begin(), pairs.end());
        
        vector<int> result(n);
        
        // Group connected elements and place them in order
        for (int i = 0; i < n; ) {
            int j = i;
            vector<int> indices;
            
            // Find the contiguous group of values with adjacent difference <= limit
            while (j < n && (j == i || pairs[j].first - pairs[j - 1].first <= limit)) {
                indices.push_back(pairs[j].second);
                j++;
            }
            
            // Sort original indices to place smaller elements in earlier positions
            sort(indices.begin(), indices.end());
            
            // Assign sorted values of the group to sorted indices
            for (int k = 0; k < indices.size(); ++k) {
                result[indices[k]] = pairs[i + k].first;
            }
            
            i = j; // Move to the next group
        }
        
        return result;
    }
};