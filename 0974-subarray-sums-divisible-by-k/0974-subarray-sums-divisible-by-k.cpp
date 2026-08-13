class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remainderCount(k, 0);
        
        remainderCount[0] = 1;
        
        int runningSum = 0;
        int result = 0;
        
        for (int num : nums) {
            runningSum += num;
            
            int remainder = (runningSum % k + k) % k;
            
            result += remainderCount[remainder];
            
            remainderCount[remainder]++;
        }
        
        return result;
    }
};