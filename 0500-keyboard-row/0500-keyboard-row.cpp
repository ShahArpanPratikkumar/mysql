class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Map each letter ('a' to 'z') to its row number (1, 2, or 3)
        int rowMap[26] = {
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, // a-m
            3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3  // n-z
        };

        vector<string> result;

        for (const string& word : words) {
            int targetRow = rowMap[tolower(word[0]) - 'a'];
            bool isValid = true;

            for (char c : word) {
                if (rowMap[tolower(c) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(word);
            }
        }

        return result;
    }
};