#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Helper function to count unique amounts <= x using Inclusion-Exclusion
        auto countAmounts = [&](long long x) {
            long long count = 0;
            int totalSubsets = 1 << n;

            for (int mask = 1; mask < totalSubsets; ++mask) {
                long long currentLcm = 1;
                int bitsCount = 0;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bitsCount++;
                        long long g = std::gcd(currentLcm, (long long)coins[i]);
                        currentLcm = (currentLcm / g) * coins[i];

                        if (currentLcm > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                if (bitsCount % 2 == 1) {
                    count += x / currentLcm;
                } else {
                    count -= x / currentLcm;
                }
            }

            return count;
        };

        // Binary search range for the answer
        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};