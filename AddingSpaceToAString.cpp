class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result ; 

        int count = 0 ;

        for(int i = 0 ; i < s.size(); i++){
            if(count < spaces.size() && (i==(spaces[count]))){
                result.push_back(' ');
                result.push_back(s[i]);
                count++;
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
