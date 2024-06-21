class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // If we encounter a zero, increment the zero count
            if (nums[right] == 0) {
                zeros++;
            }

            // If zeros exceed k, shrink the window from the left
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            // Calculate the maximum length of the window
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

/*
# Intuition
The problem requires finding the maximum length of a subarray with at most `k` zeros. This can be efficiently solved using the sliding window approach.

# Approach
1. **Sliding Window**:
   - Use two pointers, `left` and `right`, to represent the current window.
   - Iterate over the array with the `right` pointer.
   - Maintain a count of zeros in the current window.
   - If the number of zeros exceeds `k`, increment the `left` pointer to reduce the window size until the zero count is within the allowed limit.
   - Update the maximum length of the window during the iteration.

# Complexity
- Time complexity:
  $$O(n)$$ where `n` is the length of the input array. Each element is processed at most twice (once by `right` and once by `left`).

- Space complexity:
  $$O(1)$$ as we use a constant amount of extra space.

# Dry Run
Let's dry run the example `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`:

1. **Initialize**:
   - `left = 0`
   - `zeros = 0`
   - `maxLength = 0`

2. **Iterate**:
   - At `right = 0`: `nums[0] = 1`, `zeros = 0`, `maxLength = 1`
   - At `right = 1`: `nums[1] = 1`, `zeros = 0`, `maxLength = 2`
   - At `right = 2`: `nums[2] = 1`, `zeros = 0`, `maxLength = 3`
   - At `right = 3`: `nums[3] = 0`, `zeros = 1`, `maxLength = 4`
   - At `right = 4`: `nums[4] = 0`, `zeros = 2`, `maxLength = 5`
   - At `right = 5`: `nums[5] = 0`, `zeros = 3`
     - `zeros > k`, increment `left` to 1, `zeros = 2`
   - Continue this process...
   - Final `maxLength = 6` for subarray `[1,1,1,0,0,1,1,1,1]`.

The dry run confirms that the function correctly calculates the longest subarray with at most `k` zeros.
*/
