class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mymap;
        vector<int> result;
        vector<int> leftovers;

        // Count the frequency of each element in arr1
        for (int num : arr1) {
            mymap[num]++;
        }

        // Add elements to result based on the order in arr2
        for (int num : arr2) {
            int freq = mymap[num];
            for (int k = 0; k < freq; k++) {
                result.push_back(num);
            }
            mymap[num] = 0;  // Mark as processed
        }

        // Collect remaining elements
        for (auto it : mymap) {
            if (it.second > 0) {
                for (int k = 0; k < it.second; k++) {
                    leftovers.push_back(it.first);
                }
            }
        }

        // Sort and add the remaining elements
        sort(leftovers.begin(), leftovers.end());
        result.insert(result.end(), leftovers.begin(), leftovers.end());

        return result;
    }
};
