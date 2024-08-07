class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int times = piles.size()/3;
        int i = 1;
        int sum = 0;
        while(times>0){
            sum+=piles[i];
            times-=1;
            i+=2;
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
