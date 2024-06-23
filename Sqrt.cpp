class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long midValue = mid * mid;
            int target = x;

            if (midValue == target) {
                return mid;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};

/*
# Intuition
To find the square root of a non-negative integer `x`, we can use binary search. The problem can be reduced to finding the largest integer `mid` such that `mid * mid` is less than or equal to `x`.

# Approach
1. Initialize `left` to 1 and `right` to `x`.
2. Perform a binary search:
   - Calculate `mid` as the middle value between `left` and `right`.
   - Compute `mid * mid` and compare it to `x`.
   - If `mid * mid` equals `x`, return `mid` as the square root.
   - If `mid * mid` is less than `x`, move the `left` pointer to `mid + 1`.
   - If `mid * mid` is greater than `x`, move the `right` pointer to `mid - 1`.
3. When the loop exits, `right` will be the largest integer for which `right * right` is less than or equal to `x`.

# Complexity
- Time complexity:
  $$O(\log x)$$ since we are using binary search, which repeatedly divides the search space in half.

- Space complexity:
  $$O(1)$$ since we are using a constant amount of extra space.

# Dry Run
Let's dry run the example `x = 8`:

1. Initialize:
   - `left = 1`
   - `right = 8`

2. Perform binary search:
   - First iteration:
     - `mid = (1 + 8) / 2 = 4`
     - `midValue = 4 * 4 = 16` (greater than 8), update `right = 3`
   - Second iteration:
     - `mid = (1 + 3) / 2 = 2`
     - `midValue = 2 * 2 = 4` (less than 8), update `left = 3`
   - Third iteration:
     - `mid = (3 + 3) / 2 = 3`
     - `midValue = 3 * 3 = 9` (greater than 8), update `right = 2`

3. The loop exits, and the final value of `right` is 2, which is the largest integer such that `2 * 2 <= 8`.

The dry run confirms that the function correctly calculates the integer square root of `x`.
*/
