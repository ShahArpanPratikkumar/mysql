class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Frequency array for available digits
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Iterate through all 3-digit even numbers (100 to 998)
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;       // Hundreds digit
            int d2 = (num / 10) % 10; // Tens digit
            int d3 = num % 10;        // Units digit

            vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            // Verify if required digit frequencies are satisfied
            bool canForm = true;
            for (int i = 0; i < 10; i++) {
                if (req[i] > freq[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                count++;
            }
        }

        return count;
    }
};