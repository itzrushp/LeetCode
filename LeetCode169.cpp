/*# Intuition
The Boyer-Moore Voting Algorithm is a well-known algorithm used to find the majority element in an array, where the majority element is the one that appears more than ⌊n/2⌋ times. The algorithm works in linear time and constant space.

# Approach
1. **Initialization**: Start with the first element of the array as the `voter` and set `votes` to 1.
2. **Iteration**: Traverse through the array starting from the second element.
   - If the current element is the same as the `voter`, increment `votes`.
   - Otherwise, decrement `votes`. If `votes` becomes 0, update `voter` to the current element and reset `votes` to 1.
3. **Return the `voter`**: After completing the traversal, the `voter` will be the majority element.

This approach ensures that the majority element (if it exists) will be identified by the end of the array traversal.

# Complexity
- Time complexity: $$O(n)$$, where n is the number of elements in the array. We only make one pass through the array.
- Space complexity: $$O(1)$$, as we only use a few extra variables.

# Code
```cpp*/
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int voter = nums[0];
        int votes = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == voter) {
                votes++;
            } else {
                votes--;
                if (votes == 0) {
                    voter = nums[i];
                    votes = 1;
                }
            }
        }
        
        return voter;
    }
};
/*Explanation:
Initialization: We start by assuming the first element nums[0] is the majority element (voter) and initialize votes to 1.
Traversal and Voting:
For each subsequent element, if it matches the current voter, we increment the votes.
If it does not match, we decrement the votes. When votes reaches 0, we change the voter to the current element and reset votes to 1.
Return the Majority Element: After completing the iteration over the array, the voter variable holds the majority element.
This algorithm effectively identifies the majority element in a single pass through the array, using constant additional space.*/
