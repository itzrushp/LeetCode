// Intuition
// The problem requires calculating the sum of "beauties" of all possible substrings of a given string `s`.
// The beauty of a substring is defined as the difference between the frequency of the most frequent character and the frequency of the least frequent character in that substring.

// Approach
// - Iterate through all possible substrings of the input string.
// - For each substring, maintain a frequency count of characters.
// - Calculate the beauty for each substring by finding the difference between the maximum and minimum frequency (excluding zero frequencies).
// - Sum up the beauties of all substrings and return the result.

// Complexity
// - Time complexity: O(n^2 * 26), where n is the length of the string `s`.
//   This is because for each substring (which are O(n^2) in total), we iterate over a fixed size frequency map (26 letters).
// - Space complexity: O(1), since the space used by the frequency map is constant (26 elements).

#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    int beauty(const std::vector<int>& mapy) {
        int mf = INT_MIN; // max frequency
        int lf = INT_MAX; // min frequency (excluding zeros)
        
        for (int i = 0; i < 26; i++) {
            if (mapy[i] > 0) {
                if (mapy[i] > mf) {
                    mf = mapy[i];
                }
                if (mapy[i] < lf) {
                    lf = mapy[i];
                }
            }
        }
        
        return (mf - lf);
    }

    int beautySum(const std::string& s) {
        int res = 0;
        
        for (int i = 0; i < s.length(); i++) {
            std::vector<int> mapy(26, 0);
            for (int j = i; j < s.length(); j++) {
                mapy[s[j] - 'a']++;
                res += beauty(mapy);
            }
        }
        
        return res;
    }
};
