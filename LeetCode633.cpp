#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long

class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        long long l = 0;
        long long h = sqrt(c);

        while (l <= h) {
            long long sum = l * l + h * h;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                l++;
            } else {
                h--;
            }
        }
        return false;
    }
};
