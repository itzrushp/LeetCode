class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer(queries.size(), 0);
        
        // Create prefix XOR array
        for (int i = 1; i < arr.size(); i++) {
            arr[i] ^= arr[i - 1];
        }
        
        // Process each query
        int count = 0;
        for (const vector<int>& q : queries) {
            if (q[0] == 0) {
                answer[count] = arr[q[1]];
            } else {
                answer[count] = arr[q[1]] ^ arr[q[0] - 1];
            }
            count++;
        }
        
        return answer;
    }
};
