class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last_match(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last_match[j] = i;
                j--;
            }
        }

        vector<int> result;
        bool changed = false;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                result.push_back(i);
                j++;
            } 
            else if (!changed) {
                if (j == m - 1 || last_match[j + 1] > i) {
                    result.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }

        return result.size() == m ? result : vector<int>();
    }
};