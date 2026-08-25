class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result(m * n);
        
        int row = 0, col = 0;
        
        for (int i = 0; i < m * n; ++i) {
            result[i] = mat[row][col];
            
            // Moving Up-Right
            if ((row + col) % 2 == 0) {
                if (col == n - 1) {
                    row++; // Hit right border, move down
                } else if (row == 0) {
                    col++; // Hit top border, move right
                } else {
                    row--;
                    col++;
                }
            } 
            // Moving Down-Left
            else {
                if (row == m - 1) {
                    col++; // Hit bottom border, move right
                } else if (col == 0) {
                    row++; // Hit left border, move down
                } else {
                    row++;
                    col--;
                }
            }
        }
        
        return result;
    }
};