class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return maxIndex >= nums.size() - 1;
    }
};

/*
# Intuition
The task is to determine if it's possible to reach the last index of the array given that each element in the array represents the maximum jump length at that position. By keeping track of the farthest reachable index at each step, we can decide if reaching the end is possible.

# Approach
1. Initialize `maxIndex` to 0, which tracks the farthest index reachable.
2. Iterate through the array:
   - If the current index `i` is greater than `maxIndex`, return false because we cannot move past this point.
   - Update `maxIndex` to be the maximum of itself and `i + nums[i]`.
3. If the loop completes, return true if `maxIndex` is greater than or equal to the last index.

# Complexity
- Time complexity:
  $$O(n)$$, where n is the length of the `nums` vector. Each element is processed once.

- Space complexity:
  $$O(1)$$, since only a constant amount of extra space is used.

# Dry Run
Let's dry run with an example:
`nums = [2, 3, 1, 1, 4]`

1. Initialize `maxIndex = 0`.
2. Iterate through the array:
   - At `i = 0`, `maxIndex = max(0, 0 + 2) = 2`.
   - At `i = 1`, `maxIndex = max(2, 1 + 3) = 4`.
   - At `i = 2`, `maxIndex = max(4, 2 + 1) = 4`.
   - At `i = 3`, `maxIndex = max(4, 3 + 1) = 4`.
   - At `i = 4`, `maxIndex = max(4, 4 + 4) = 8`.

Since `maxIndex` is greater than or equal to the last index, return true.
*/
