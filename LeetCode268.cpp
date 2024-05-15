class Solution {
public:
    // # Intuition
   /* <!-- 
    To find the missing number in the given array, we can calculate the sum of the first n natural numbers and subtract the sum of the numbers in the array from it. The difference will be the missing number.
    -->

    # Approach
    <!-- 
    - Calculate the sum of the first n natural numbers using the formula (n * (n + 1)) / 2.
    - Calculate the sum of the numbers in the given array.
    - Return the difference between the sum of the first n natural numbers and the sum of the numbers in the array, which represents the missing number.
    -->*/

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = (n * (n + 1)) / 2;
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum2 += nums[i];
        }
        return sum1 - sum2;
    }
};
