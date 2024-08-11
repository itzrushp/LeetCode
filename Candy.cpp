//O(N) O(1)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;  // Start with one candy for the first child
        int i = 1;
        
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1; // Equal ratings: just give 1 candy
                i++;
                continue;
            }

            int peak = 1; // Reset peak
            // Ascending sequence
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            
            int down = 0; // Reset down
            // Descending sequence
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum += down;
                i++;
            }

            // If descending sequence is longer than the peak, adjust the sum
            if (down >= peak) {
                sum += (down - peak + 1); 
            }
        }
        
        return sum;
    }
};
