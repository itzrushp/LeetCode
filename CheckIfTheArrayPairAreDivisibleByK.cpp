class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // Count the frequency of each remainder
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handling negative numbers
            remainderCount[remainder]++;
        }
        
        // Check if the remainders can be paired
        if (remainderCount[0] % 2 != 0) return false;
        
        for (int i = 1; i <= k/2; i++) {
            if (remainderCount[i] != remainderCount[k-i]) return false;
        }
        
        return true;
    }
};
