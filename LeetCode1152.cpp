class Solution {
public:
    int sol(vector<int>& arr, int mid, int n) {
        int curr = arr[0];
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] - curr >= mid) {
                ans++;
                curr = arr[i];
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();

        int low = 0, high = position[n - 1], mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (sol(position, mid, n) >= m) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

/*
# Intuition
The problem is to place `m` balls in `n` positions such that the minimum distance between any two balls is maximized. This can be solved using a binary search approach on the minimum possible distance.

# Approach
1. **Sort the Positions**: Sort the given positions array to enable a binary search for the maximum minimum distance.
2. **Binary Search Setup**:
   - Set `low` to 0 and `high` to the difference between the maximum and minimum positions.
3. **Check Feasibility**:
   - Define a helper function `sol` to check if it is possible to place `m` balls with at least `mid` distance apart.
   - Use binary search to adjust `low` and `high` based on the feasibility of placing balls with the current `mid` distance.

# Complexity
- Time complexity:
  $$O(n \log d)$$ where `n` is the number of positions and `d` is the difference between the maximum and minimum positions. This accounts for the sort operation and the binary search with the helper function.

- Space complexity:
  $$O(1)$$ since the algorithm only uses a few extra variables.

# Dry Run
Let's dry run the example `position = [1, 2, 3, 4, 7]`, `m = 3`:

1. **Sort the Positions**:
   - Sorted positions: `[1, 2, 3, 4, 7]`

2. **Binary Search Setup**:
   - Initial `low = 0`, `high = 6` (difference between `7` and `1`).

3. **Binary Search Execution**:
   - Check `mid = 3`:
     - Feasibility: Possible to place `3` balls with at least `3` distance apart.
   - Adjust `low` to `4`.
   - Check `mid = 5`:
     - Feasibility: Not possible to place `3` balls with at least `5` distance apart.
   - Adjust `high` to `4`.
   - Check `mid = 4`:
     - Feasibility: Possible to place `3` balls with at least `4` distance apart.
   - Adjust `low` to `5`.

Final `high` value `4` is the maximum minimum distance.

The dry run confirms that the solution correctly identifies the maximum minimum distance for placing the balls.
*/
