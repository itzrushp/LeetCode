class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = -1;
        int n = nums.size();
        int sum = 0;


        for(int i: nums){
            if(i >= max){
                max = i;
            }
        }

        for(int i = 0; i<k ;i++){
            sum += max + i;
        }

        return sum;
    }
};
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
