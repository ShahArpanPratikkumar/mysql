class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;

        int totalPoisonedTime = 0;
        int n = timeSeries.size();

        for (int i = 0; i < n - 1; ++i) {
            totalPoisonedTime += std::min(duration, timeSeries[i + 1] - timeSeries[i]);
        }

        totalPoisonedTime += duration;

        return totalPoisonedTime;
    }
};