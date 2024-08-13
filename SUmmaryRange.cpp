/*# Intuition
When given a sorted list of integers, the goal is to summarize consecutive sequences into a compact string format. For example, a sequence `[1, 2, 3]` should be summarized as `"1->3"`, while individual numbers should remain as is.

# Approach
1. **Iterate Through the List**:
   - Traverse the list while identifying the start of each potential range.
   
2. **Identify Ranges**:
   - For each number, continue to the next if it's consecutive. Track the start and end of these consecutive ranges.

3. **Format Output**:
   - If a range consists of more than one number, format it as `"start->end"`.
   - If the range is a single number, simply convert it to a string.

4. **Edge Cases**:
   - Handle cases where the list is empty or contains only one element.

# Complexity
- **Time complexity**: $$O(n)$$ 
  - Each number is processed once.
- **Space complexity**: $$O(1)$$ 
  - Aside from the output, no additional space is required proportional to the input size.

# Code
```cpp*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) return result;
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            // Find the end of the current range
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            if (start != nums[i]) {
                // If it's a range, add it in the format "start->end"
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                // If it's a single number, just add it as a string
                result.push_back(to_string(start));
            }
        }
        
        return result;
    }
};
