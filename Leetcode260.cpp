/* # Intuition
The problem requires finding two unique numbers in an array where every other number appears exactly twice. XOR operations can help in identifying unique numbers due to their properties.

# Approach
1. **XOR All Elements**:
   - XOR all elements in the array. The result is the XOR of the two unique numbers, as duplicates cancel out.
   
2. **Identify Set Bit**:
   - Find the first set bit (from the right) in the XOR result. This bit differs between the two unique numbers.

3. **Partition and XOR**:
   - Partition the array into two groups based on the identified set bit. XOR the elements in each group to find the two unique numbers.

# Complexity
- Time complexity:
  $$O(n)$$ for traversing the array to find the XOR result and then partitioning the array.

- Space complexity:
  $$O(1)$$ as we only use a few extra variables.

# Dry Run
Let's dry run the example `nums = [1, 2, 1, 3, 2, 5]`:

1. **XOR All Elements**:
   - `result = 1 ^ 2 ^ 1 ^ 3 ^ 2 ^ 5 = 3 ^ 5 = 6` (binary `0110`)

2. **Identify Set Bit**:
   - First set bit from the right in `0110` is at position 1.

3. **Partition and XOR**:
   - Partition based on the set bit at position 1:
     - Group 1 (set bit): `[2, 2]` -> XOR result `2`
     - Group 2 (unset bit): `[1, 1, 3, 5]` -> XOR result `6`
     - Group 2 refinement:
       - `[1, 1]` -> XOR result `0`
       - `[3, 5]` -> XOR result `6`

The dry run shows that the solution correctly identifies `3` and `5` as the unique numbers.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int result = 0;
        for(int i = 0; i < nums.size(); i++) {  // Finding the final XOR result
            result = result ^ nums[i];
        }

        // Now we will find the first set bit position from the right
        int pos = 0;
        int original_xor = result;
        while((result & 1) == 0 && pos < 32) {  // Find the first set bit
            pos++;
            result = result >> 1; 
        }

        // Now we are going to filter elements based on the same set bit
        int bitcheck = 1 << pos;
        int num1 = 0, num2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] & bitcheck) != 0) {
                num1 = num1 ^ nums[i];  // XORing numbers with the set bit at pos
            } else {
                num2 = num2 ^ nums[i];  // XORing numbers without the set bit at pos
            }
        }

        // Return the two unique numbers
        vector<int> ret(2);
        ret[0] = num1;
        ret[1] = num2;

        return ret;
    }
};






