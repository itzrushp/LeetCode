class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result (2,0);
        int l =0 ; 
        int  r = numbers.size()-1;
        while(l<=r){
            if((numbers[l] + numbers[r])>target){
                r--;
            }
            else if((numbers[l]+numbers[r])< target){
                l++;
            }
            else{
                result[0] = l+1;
                result[1] = r+1;
                return result;
            }
        }
        return result;
        

    }
};
