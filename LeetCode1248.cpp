class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int odd = 0;
        int count = 0;
        int prefix_odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) {
                ++odd;
                prefix_odd_count = 0;
            }
            
            while (odd == k) {
                ++prefix_odd_count;
                if (nums[left] % 2 != 0) {
                    --odd;
                }
                ++left;
            }
            
            count += prefix_odd_count;
        }
        
        return count;
    }
};

/*
# Intuition
To find the number of subarrays with exactly `k` odd numbers, we need an efficient way to track subarrays as we iterate through the list. By using a sliding window approach, we can dynamically adjust the window size to include exactly `k` odd numbers and count the valid subarrays.

# Approach
1. Use two pointers (`left` and `right`) to maintain a sliding window.
2. Traverse through the array with the `right` pointer:
   - Increment the `odd` counter for each odd number encountered.
   - When the count of odd numbers reaches `k`, move the `left` pointer to count all possible subarrays that end at `right` and have exactly `k` odd numbers.
   - Adjust the `left` pointer and `odd` counter when necessary to ensure the window always contains exactly `k` odd numbers.
3. Accumulate the count of valid subarrays for each position of the `right` pointer.

# Complexity
- Time complexity:
  $$O(n)$$ where `n` is the length of the array. Each element is processed at most twice by the two pointers.

- Space complexity:
  $$O(1)$$ since we are using a fixed amount of extra space.

# Dry Run
Let's dry run the example `nums = [2,2,2,1,2,2,1,2,2,2]`, `k = 2`:

1. Initialize:
   - `left = 0`
   - `odd = 0`
   - `count = 0`
   - `prefix_odd_count = 0`

2. Traverse `nums` with the `right` pointer:
   - At `right = 0`: `nums[0] = 2` (even), `odd = 0`
   - At `right = 1`: `nums[1] = 2` (even), `odd = 0`
   - At `right = 2`: `nums[2] = 2` (even), `odd = 0`
   - At `right = 3`: `nums[3] = 1` (odd), `odd = 1`
   - At `right = 4`: `nums[4] = 2` (even), `odd = 1`
   - At `right = 5`: `nums[5] = 2` (even), `odd = 1`
   - At `right = 6`: `nums[6] = 1` (odd), `odd = 2`
     - Increment `prefix_odd_count`, `count += prefix_odd_count`
   - At `right = 7`: `nums[7] = 2` (even), `count += prefix_odd_count`
   - Continue to adjust `left` pointer to maintain exactly `k` odd numbers in the window.
   - Final `count = 16` for all valid subarrays.

The dry run confirms that the function correctly calculates the number of subarrays with exactly `k` odd numbers.
*/
