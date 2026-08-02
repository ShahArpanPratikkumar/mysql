class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Store pairs of (score, original_index)
        vector<pair<int, int>> sortedScores(n);
        for (int i = 0; i < n; ++i) {
            sortedScores[i] = {score[i], i};
        }
        
        // Sort in descending order of scores
        sort(sortedScores.rbegin(), sortedScores.rend());
        
        vector<string> result(n);
        
        // Assign ranks based on sorted position
        for (int rank = 0; rank < n; ++rank) {
            int originalIndex = sortedScores[rank].second;
            
            if (rank == 0) {
                result[originalIndex] = "Gold Medal";
            } else if (rank == 1) {
                result[originalIndex] = "Silver Medal";
            } else if (rank == 2) {
                result[originalIndex] = "Bronze Medal";
            } else {
                result[originalIndex] = to_string(rank + 1);
            }
        }
        
        return result;
    }
};