class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMasks;
        
        // Track reserved seats for middle columns (2 through 9) using bitmask
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            // Only columns 2-9 affect group placement
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        // Each unreserved row can seat up to 2 groups
        int maxGroups = (n - rowMasks.size()) * 2;
        
        // Bitmasks for the 3 possible block placements (relative to cols 2-9, 0-indexed):
        // Left block:   cols 2, 3, 4, 5  -> bits 0, 1, 2, 3  -> 0b00001111 (15)
        // Middle block: cols 4, 5, 6, 7  -> bits 2, 3, 4, 5  -> 0b00111100 (60)
        // Right block:  cols 6, 7, 8, 9  -> bits 4, 5, 6, 7  -> 0b11110000 (240)
        int leftMask = 15;
        int middleMask = 60;
        int rightMask = 240;
        
        for (const auto& [row, mask] : rowMasks) {
            bool leftFree = (mask & leftMask) == 0;
            bool rightFree = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;
            
            if (leftFree && rightFree) {
                maxGroups += 2;
            } else if (leftFree || rightFree || middleFree) {
                maxGroups += 1;
            }
        }
        
        return maxGroups;
    }
};