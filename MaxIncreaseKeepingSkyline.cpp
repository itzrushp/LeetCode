class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> max_row(n, 0);
        vector<int> max_col(n, 0);
        
        // Determine the maximum height for each row
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                max_row[r] = max(max_row[r], grid[r][c]);
            }
        }
        
        // Determine the maximum height for each column
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < n; r++) {
                max_col[c] = max(max_col[c], grid[r][c]);
            }
        }
        
        // Calculate the maximum increase
        int total_increase = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                total_increase += min(max_row[r], max_col[c]) - grid[r][c];
            }
        }
        
        return total_increase;
    }
};
