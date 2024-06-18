class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if n is positive, a power of 2, and has its single 1-bit at an odd position
        if (n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0) {
            return true;
        }
        return false;
    }
};

/*
# Intuition
To determine if a number is a power of four, we need to check a few conditions. First, the number must be positive. Second, the number must be a power of two. Third, among powers of two, the number must be a power of four specifically, which means its single 1-bit must be located in an odd position in its binary representation.

# Approach
1. **Check if Positive**: The number must be greater than 0.
2. **Check Power of Two**: A power of two has exactly one bit set in its binary representation, i.e., `n & (n - 1) == 0`.
3. **Check Power of Four**: Among powers of two, powers of four have their single 1-bit at odd positions. This can be checked using the mask `0x55555555` which in binary is `01010101010101010101010101010101`. The mask ensures that the 1-bit is at the correct position for powers of four.

# Complexity
- Time complexity:
  $$O(1)$$ because the operations are basic arithmetic and bitwise operations which take constant time.

- Space complexity:
  $$O(1)$$ because no additional space proportional to the input size is used.

# Dry Run
Let's dry run the example `n = 16`:

1. **Check if Positive**:
   - `n = 16` which is greater than 0, so pass this check.

2. **Check Power of Two**:
   - `16` in binary is `10000`.
   - `16 & (16 - 1) = 10000 & 01111 = 00000`, which equals 0, so pass this check.

3. **Check Power of Four**:
   - `16` in binary is `10000`.
   - `10000 & 0x55555555 = 10000 & 01010101010101010101010101010101 = 0`, which fails this check.

Thus, the function returns `false` indicating that 16 is not a power of four.
*/
