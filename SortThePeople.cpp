class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of indices
        vector<int> indices(names.size());
        iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, 2, ..., n-1

        // Sort indices based on corresponding heights in descending order
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        // Create the result vector by reordering names based on sorted indices
        vector<string> result(names.size());
        for (int i = 0; i < indices.size(); ++i) {
            result[i] = names[indices[i]];
        }

        return result;
    }
};

