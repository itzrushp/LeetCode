class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
    int ans = 0;
    int flippedTime = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k && nums[i - k] == 2)
        --flippedTime;
      if (flippedTime % 2 == nums[i]) {
        if (i + k > nums.size())
          return -1;
        ++ans;
        ++flippedTime;
        nums[i] = 2;
      }
    }

    return ans;
  }
};

/*
# Intuition
To solve the problem of flipping exactly `k` consecutive bits to make the array all 1s, we can leverage a greedy approach with tracking of the flipping operations. When encountering a 0 that should be a 1, we flip `k` consecutive bits starting from that position. We use a marker (2) to indicate where a flip has been started.

# Approach
1. Initialize `ans` to count the number of flips and `flippedTime` to track the cumulative number of flips affecting the current position.
2. Iterate through the array:
   - If the current position is past `k` positions and the bit `k` positions back was flipped, decrement `flippedTime`.
   - Check if the current bit, after accounting for previous flips (`flippedTime`), is incorrect (should be 1 but is 0 or vice versa). If so:
     - If flipping `k` bits from the current position exceeds the array length, return -1.
     - Increment `ans` and `flippedTime`.
     - Mark the current position with 2 to indicate a flip has started here.
3. Return the total number of flips.

# Complexity
- Time complexity: 
  $$O(n)$$, where `n` is the length of the input array. We iterate through the array once.
- Space complexity: 
  $$O(1)$$, only a few extra variables are used, and the array is modified in place.

# Dry Run
Let's dry run with an example:
`nums = [0, 1, 0, 1, 0, 1, 0], k = 3`

1. Initial state:
   - `ans = 0`
   - `flippedTime = 0`
   - `nums = [0, 1, 0, 1, 0, 1, 0]`
2. First iteration (i=0):
   - `nums[0]` is 0 and `flippedTime % 2` is 0, so we need to flip.
   - Check if `i + k > nums.size()`, which is false.
   - Increment `ans` and `flippedTime`.
   - Mark `nums[0]` with 2.
   - `nums = [2, 1, 0, 1, 0, 1, 0]`
3. Second iteration (i=1):
   - `nums[1]` is 1 and `flippedTime % 2` is 1, no flip needed.
   - `nums = [2, 1, 0, 1, 0, 1, 0]`
4. Third iteration (i=2):
   - `nums[2]` is 0 and `flippedTime % 2` is 1, so we need to flip.
   - Check if `i + k > nums.size()`, which is false.
   - Increment `ans` and `flippedTime`.
   - Mark `nums[2]` with 2.
   - `nums = [2, 1, 2, 1, 0, 1, 0]`
5. Fourth iteration (i=3):
   - `nums[3]` is 1 and `flippedTime % 2` is 0, so we need to flip.
   - Check if `i + k > nums.size()`, which is false.
   - Increment `ans` and `flippedTime`.
   - Mark `nums[3]` with 2.
   - `nums = [2, 1, 2, 2, 0, 1, 0]`
6. Fifth iteration (i=4):
   - `nums[4]` is 0 and `flippedTime % 2` is 1, no flip needed.
   - `nums = [2, 1, 2, 2, 0, 1, 0]`
7. Sixth iteration (i=5):
   - `nums[5]` is 1 and `flippedTime % 2` is 0, no flip needed.
   - `nums = [2, 1, 2, 2, 0, 1, 0]`
8. Seventh iteration (i=6):
   - `nums[6]` is 0 and `flippedTime % 2` is 1, no flip needed.
   - `nums = [2, 1, 2, 2, 0, 1, 0]`
9. End of iteration, `ans = 3`.

Return `ans`, which is 3.

This dry run shows how the algorithm correctly counts the number of flips needed.
*/
