class Solution {
public:
    static bool comparator(vector<int> a , vector<int> b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int count = 1;
        int freetime = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= freetime){
                count++;
                freetime = intervals[i][1];
            }
        }
        return intervals.size() - count;
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
The problem requires us to find the minimum number of intervals we need to remove to make the rest of the intervals non-overlapping. By sorting the intervals based on their end times, we can iteratively select the intervals that do not overlap with the previously selected interval.

# Approach
1. Sort the intervals based on their end times using a custom comparator.
2. Initialize a `count` variable to keep track of the maximum number of non-overlapping intervals.
3. Iterate through the intervals, and for each interval, check if it starts after the end time of the previously selected interval. If it does, increment the count and update the end time.
4. The answer is the total number of intervals minus the count of non-overlapping intervals.

# Complexity
- Time complexity: $$O(n \log n)$$ due to sorting the intervals.
- Space complexity: $$O(1)$$ as we are using constant extra space.

# Example Dry Run
For intervals `[[1, 2], [2, 3], [3, 4], [1, 3]]`:
1. After sorting by end time, we get `[[1, 2], [1, 3], [2, 3], [3, 4]]`.
2. Start with `freetime = 2` and count the number of non-overlapping intervals.
3. Skip intervals `[1, 3]` and `[2, 3]` since they overlap, but include `[3, 4]`.
4. The result is `4 - 2 = 2` intervals to remove.

*/
