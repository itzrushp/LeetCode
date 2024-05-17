/* Intuition
The problem involves sorting an array of integers where the integers are only 0, 1, and 2. This can be effectively solved using a variant of the Dutch National Flag algorithm,
which is specifically designed for sorting arrays with a fixed number of distinct values. The main idea is to partition the array into three sections: one for each value (0, 1, and 2).

Approach
Initialization:

l (left pointer) is set to the start of the array to track the position for 0s.

r (right pointer) is set to the end of the array to track the position for 2s.

A variable i is used to traverse the array.
Traversal:

Traverse the array using i from the beginning to the end (up to r).
When encountering a 0 at index i, swap it with the value at l, increment both i and l.

When encountering a 1, just move to the next index by incrementing i.

When encountering a 2, swap it with the value at r, decrement r (without incrementing i as the new value at i needs to be checked).
Termination:

The loop terminates when i exceeds r, ensuring all 0s are at the beginning, followed by all 1s, and all 2s at the end.

Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(1)O(1)O(1)

Code*/
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
                swap(nums[i],nums[r]);
                r--;
            }
        }
    }
};
