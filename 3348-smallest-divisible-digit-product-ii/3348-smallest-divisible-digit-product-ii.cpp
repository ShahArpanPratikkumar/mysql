#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factors getFactors(long long t) {
        Factors f;
        while (t % 2 == 0) { f.c2++; t /= 2; }
        while (t % 3 == 0) { f.c3++; t /= 3; }
        while (t % 5 == 0) { f.c5++; t /= 5; }
        while (t % 7 == 0) { f.c7++; t /= 7; }
        if (t > 1) return {-1, -1, -1, -1};
        return f;
    }

    Factors removeDigit(Factors f, int d) {
        if (d == 2) f.c2--;
        else if (d == 3) f.c3--;
        else if (d == 4) f.c2 -= 2;
        else if (d == 5) f.c5--;
        else if (d == 6) { f.c2--; f.c3--; }
        else if (d == 7) f.c7--;
        else if (d == 8) f.c2 -= 3;
        else if (d == 9) f.c3 -= 2;
        return f;
    }

    // Helper to dynamically build the shortest/smallest sequence of digits for remaining prime powers
    string getMinDigits(Factors f) {
        int c2 = max(0, f.c2);
        int c3 = max(0, f.c3);
        int c5 = max(0, f.c5);
        int c7 = max(0, f.c7);

        string res = "";
        res.append(c7, '7');
        res.append(c5, '5');

        // Greedily combine 3s into 9s and 2s into 8s
        res.append(c3 / 2, '9');
        c3 %= 2;

        res.append(c2 / 3, '8');
        c2 %= 3;

        // Handle leftovers (c2 < 3, c3 < 2)
        if (c2 == 2 && c3 == 1) {
            res += "26"; // 2 * 6 = 12 (represents 2^2 * 3^1)
        } else if (c2 == 2 && c3 == 0) {
            res += "4";  // 2^2
        } else if (c2 == 1 && c3 == 1) {
            res += "6";  // 2 * 3
        } else if (c2 == 1 && c3 == 0) {
            res += "2";
        } else if (c2 == 0 && c3 == 1) {
            res += "3";
        }

        sort(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        Factors targetF = getFactors(t);
        if (targetF.c2 == -1) return "-1";

        int n = num.length();
        vector<Factors> prefF(n + 1);
        prefF[0] = targetF;

        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
            prefF[i + 1] = removeDigit(prefF[i], num[i] - '0');
        }

        // Check if num itself (if zero-free) already satisfies t
        if (firstZero == -1) {
            string minSuff = getMinDigits(prefF[n]);
            if (minSuff.empty()) return num;
        }

        int maxMatch = (firstZero == -1) ? n - 1 : firstZero;

        // Try changing digit at index i to something strictly larger than num[i]
        for (int i = maxMatch; i >= 0; i--) {
            int startDigit = (num[i] - '0') + 1;
            Factors curF = prefF[i];

            for (int d = startDigit; d <= 9; d++) {
                Factors nextF = removeDigit(curF, d);
                string suff = getMinDigits(nextF);
                int remLen = n - 1 - i;

                if ((int)suff.length() <= remLen) {
                    string res = num.substr(0, i);
                    res += to_string(d);
                    res.append(remLen - suff.length(), '1');
                    res += suff;
                    return res;
                }
            }
        }

        // If no valid number of length n exists, create minimal valid number of length n + 1 (or longer if needed)
        string suff = getMinDigits(targetF);
        int targetLen = max(n + 1, (int)suff.length());
        string res = "";
        res.append(targetLen - suff.length(), '1');
        res += suff;

        return res;
    }
};