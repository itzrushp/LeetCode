class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int subset = 1 << n;
        for (int i = 0; i < subset; i++) {
            vector<int> list;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    list.push_back(nums[j]);
                }
            }
            result.push_back(list);
        }
        return result;
    }
};

/*
# Intuition
To generate all possible subsets of a given set of numbers, we can utilize the concept of binary representation. Each subset can be represented by a binary number where the `i-th` bit is `1` if the corresponding element is included in the subset and `0` if it is not.

# Approach
1. Calculate the total number of subsets, which is `2^n` for a set of `n` elements.
2. Iterate through all possible subsets (from `0` to `2^n - 1`).
3. For each subset, use its binary representation to determine which elements are included in the subset.
4. Add the subset to the result.

# Complexity
- Time complexity: 
  $$O(n \cdot 2^n)$$ where `n` is the number of elements in the input array. This accounts for generating each subset and iterating through each element to form the subset.
- Space complexity: 
  $$O(2^n)$$ for storing all subsets in the result.

# Dry Run
Let's dry run with an example:
`nums = [1, 2, 3]`

1. `n = 3`, `subset = 1 << 3 = 8`.
2. Iterate from `i = 0` to `7` (i.e., `000` to `111` in binary):
   - `i = 0` (binary `000`): subset = `[]`
   - `i = 1` (binary `001`): subset = `[1]`
   - `i = 2` (binary `010`): subset = `[2]`
   - `i = 3` (binary `011`): subset = `[1, 2]`
   - `i = 4` (binary `100`): subset = `[3]`
   - `i = 5` (binary `101`): subset = `[1, 3]`
   - `i = 6` (binary `110`): subset = `[2, 3]`
   - `i = 7` (binary `111`): subset = `[1, 2, 3]`

Thus, the function returns `[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]`.
*/
