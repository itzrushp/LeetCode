// Score After Flipping Matrix   :)   Date -> 13th March 2024

class Solution {
public:
     /* 
    Intuition
    We start by flipping the rows to maximize the value of the number. 
    Then, we flip the columns if it would increase the value. Finally, we 
    calculate the score by summing up the values of all numbers in the matrix. 

    # Approach
    
    - Flip rows with the leftmost digit as 0.
    - Flip columns if flipping that column would result in more 1s than 0s.
    - Calculate the score by converting the binary numbers to decimal. 
    
    */
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Fliping the rows 
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        // Flipping the Columns
        for(int j = 0; j < n; j++) {
            int no_of_zeros = 0;
            int no_of_ones = 0;
        
            for (int i = 0; i < m; i++) {
                if(grid[i][j] == 0) 
                    no_of_zeros++;
                else 
                    no_of_ones++;
            }
            
            if(no_of_zeros > no_of_ones) {
                for(int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculate the score
        int result = 0 ;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    result += (grid[i][j] << (n - j - 1));
                }
            }
        }
        return result;
    }
   /* 
   # Complexity
    - Time complexity:
    <!-- 
    The time complexity of this algorithm is O(m*n), where m is the number of rows and n is the number of columns in the matrix.
    -->
    
    - Space complexity:
    <!-- 
    The space complexity of this algorithm is O(1) as we are not using any extra space that scales with the input.
    -->
    */
};
