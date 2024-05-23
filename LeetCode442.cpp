/* Takes O(n) Time and O(n) Space
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mymap;

        // Count occurrences of each number
        for (int num : nums) {
            mymap[num]++;
        }

        // Collect numbers that appear more than once
        for (const auto& entry : mymap) {
            if (entry.second > 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            // If the number at this index is negative that means we have
            // Visited it already and this is the second time Thus DUPLICATE
            if (nums[index] < 0) {
                result.push_back(index + 1);
            }

            //Otherwise Make it negative :
            nums[index] = nums[index]*-1;
        }
        return result;
    }
};
