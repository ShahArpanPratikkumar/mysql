#include <vector>
#include <algorithm>

class Solution {
public:
    bool stoneGameIX(std::vector<int>& stones) {
        int cnt[3] = {0, 0, 0};
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // If the number of 0s is even, Alice wins if there is at least one 1 AND at least one 2.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        
        // If the number of 0s is odd, Alice wins if the difference between count of 1s and 2s is >= 3.
        return std::abs(cnt[1] - cnt[2]) >= 3;
    }
};