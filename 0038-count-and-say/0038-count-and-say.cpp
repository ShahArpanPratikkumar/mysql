class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for (int i = 1; i < n; ++i) {
            string next_res = "";
            int count = 1;
            
            for (size_t j = 0; j < res.length(); ++j) {
                // Check if we reached the end or if the next character is different
                if (j + 1 == res.length() || res[j] != res[j + 1]) {
                    next_res += to_string(count) + res[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            
            res = next_res;
        }
        
        return res;
    }
};