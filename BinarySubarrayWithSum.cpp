class Solution {
public:
    int NoofSubarraysWithSumLessthanEqualTogoal(vector<int>& nums, int goal){
        int count = 0;
        int l =0, r=0, sum = 0 ;
    

        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++; 
            }
            count += (r-l+1);
            r++;

        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return NoofSubarraysWithSumLessthanEqualTogoal(nums, goal) - NoofSubarraysWithSumLessthanEqualTogoal(nums, goal-1);
    }
};
