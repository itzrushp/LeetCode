class Solution {
public:
/*
    # Intuition
    To check if the array was originally sorted in non-decreasing order and then rotated some number of positions, we iterate through the array and count the number of rotations needed to make the array sorted. 
If the number of rotations is more than one, we return false; otherwise, we return true.
    -->

    # Approach
    <!-- 
    - We iterate through the array and count the number of rotations needed to make the array sorted.
    - If the number of rotations is more than one, we return false; otherwise, we return true.
    -->
*/
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int rotates = 0;

        for (int i = 0; i < n; ++i)
            if (nums[i] > nums[(i + 1) % n] && ++rotates > 1)
                return false;

        return true;
    }
/*
    # Complexity
    - Time complexity:
    <!-- 
    The time complexity of this algorithm is O(n), where n is the number of elements in the array. We iterate through the array once to check if it is sorted after rotation.
    -->
    
    - Space complexity:
    <!-- 
    The space complexity of this algorithm is O(1) as we are not using any extra space that scales with the input.
    -->
*/
};
