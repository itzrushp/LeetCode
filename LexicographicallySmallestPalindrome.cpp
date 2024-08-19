class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l= 0;
        int h = s.length()-1;
        while(l<h){
            if(s[l]!=s[h]){
                if(s[l]>s[h]){
                    s[l] = s[h];
                }else{
                    s[h]=s[l];
                }
            }
            l++;h--;
        }
        return s;
    }
};
auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
