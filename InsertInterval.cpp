#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;

        // Add all intervals that end before the start of the new interval
        while (i < n && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }

        // Merge all overlapping intervals with the new interval
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);  // Add the merged interval

        // Add all remaining intervals
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

/*

# Intuition
When given a new interval, the goal is to insert it into the list of existing intervals such that the intervals remain non-overlapping and sorted by their start times.

# Approach
1. Traverse the list of intervals:
   - Add all intervals that end before the new interval starts.
   - Merge the new interval with any overlapping intervals by adjusting the start and end times.
   - Add all remaining intervals after merging.
2. This ensures that the new interval is inserted correctly while maintaining the non-overlapping property of the intervals.

# Complexity
- Time complexity: $$O(n)$$, where `n` is the number of intervals.
- Space complexity: $$O(n)$$, for the result vector.

# Example Dry Run
For intervals `[[1, 3], [6, 9]]` and newInterval `[2, 5]`:
1. First interval `[1, 3]` overlaps with `[2, 5]`, so merge them to `[1, 5]`.
2. The final result is `[[1, 5], [6, 9]]`.

*/
