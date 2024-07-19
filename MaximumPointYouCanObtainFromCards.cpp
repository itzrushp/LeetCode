class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0;
        int rightsum = 0;

        for(int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
        }

        int max_sum = leftsum;

    
        for(int i = 0; i < k; i++) {
            leftsum -= cardPoints[k-1-i];
            rightsum += cardPoints[n-1-i];
            max_sum = max(max_sum, leftsum + rightsum);
        }

        return max_sum;
    }
};
