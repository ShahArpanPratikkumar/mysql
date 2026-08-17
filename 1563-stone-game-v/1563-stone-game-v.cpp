class Solution {
    int memo[501][501];
    int pref[501];

    int getSum(int l, int r) {
        return pref[r + 1] - pref[l];
    }

    int solve(int l, int r, vector<int>& stoneValue) {
        if (l == r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int maxScore = 0;
        for (int i = l; i < r; ++i) {
            int leftSum = getSum(l, i);
            int rightSum = getSum(i + 1, r);

            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(l, i, stoneValue));
            } else if (rightSum < leftSum) {
                maxScore = max(maxScore, rightSum + solve(i + 1, r, stoneValue));
            } else {
                maxScore = max(maxScore, leftSum + max(solve(l, i, stoneValue), solve(i + 1, r, stoneValue)));
            }
        }

        return memo[l][r] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};