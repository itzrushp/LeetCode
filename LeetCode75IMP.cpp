/*# Intuition
The problem requires us to sort an array of integers where the integers are either 0, 1, or 2.
A straightforward solution would be to count the occurrences of each integer and then overwrite the array with the correct number of 0s, 1s, and 2s.
However, this problem can be efficiently solved in a single pass using the Dutch National Flag algorithm, which is particularly useful for sorting arrays with a limited range of values.

# Approach
The Dutch National Flag algorithm sorts the array in one pass with constant space. The idea is to maintain three pointers:
- `l` for the left boundary where all elements to the left are 0.
- `r` for the right boundary where all elements to the right are 2.
- `i` for the current element being processed.

The algorithm works as follows:
1. Initialize `l` to 0 and `r` to the last index of the array.
2. Traverse the array with the pointer `i`.
3. If the current element is 0, swap it with the element at the `l` pointer and increment both `i` and `l`.
4. If the current element is 1, just move the `i` pointer.
5. If the current element is 2, swap it with the element at the `r` pointer and decrement `r` (do not increment `i` because the element swapped into position `i` needs to be processed).

# Complexity
- Time complexity: $$O(n)$$ because we process each element at most twice.
- Space complexity: $$O(1)$$ because we only use a few extra variables.

# Code
```cpp*/
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, r;
        l = 0;
        r = nums.size() - 1;
        for (int i = 0; i <= r;) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[r]);
                r--;
            }
        }
    }
};
