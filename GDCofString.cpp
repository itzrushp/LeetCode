class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, gcd(str1.length(), str2.length()));
    }

private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};

/*

# Intuition
The problem asks to find the greatest common divisor (GCD) string of two given strings. If one string can be formed by repeating another string multiple times, the problem boils down to finding the GCD of the lengths of the two strings.

# Approach
1. First, check if `str1 + str2` is equal to `str2 + str1`. This ensures that the two strings can be formed by repeating a common substring.
2. If the strings can form each other, find the GCD of their lengths.
3. The GCD of the strings will be the substring from the beginning of either string up to the GCD of their lengths.

# Complexity
- **Time complexity**: O(n), where n is the combined length of `str1` and `str2`, mainly due to the string concatenation and comparison.
- **Space complexity**: O(n), for storing the concatenated strings.

# Example Dry Run
Given `str1 = "ABCABC"` and `str2 = "ABC"`:
1. Check if `str1 + str2` equals `str2 + str1` which is `ABCABCABC` == `ABCABCABC`.
2. Find the GCD of the lengths of the two strings, which are 6 and 3 respectively, resulting in a GCD of 3.
3. Return the substring of `str1` from the beginning up to length 3, which is "ABC".

*/
