// Solution to the problem of removing outermost parentheses from a valid parentheses string.

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count = 0; // to track the depth of parentheses
        
        for (char c : s) {
            if (c == '(') {
                if (count > 0) { // do not append the outermost '('
                    result += c;
                }
                count++;
            } else if (c == ')') {
                count--;
                if (count > 0) { // do not append the outermost ')'
                    result += c;
                }
            }
        }

        return result;
    }
};

// Explanation of the solution:

/*
# Intuition
The problem requires us to remove the outermost parentheses from each primitive decomposition of a valid parentheses string.
A primitive decomposition is a non-empty substring that cannot be split further into smaller valid substrings.

# Approach
To solve this problem, we need to:
1. Track the depth of the parentheses using a counter.
2. Append characters to the result string only when they are not the outermost parentheses.

## Steps:
1. Initialize an empty string `result` to store the final output.
2. Use an integer `count` to keep track of the depth of nested parentheses.
3. Iterate through each character in the input string `s`:
   - If the character is `'('` and the current depth `count` is greater than 0, it means it is not the outermost opening parenthesis, so append it to the `result`.
   - Increase the `count` by 1 whenever you encounter `'('`.
   - If the character is `')'`, decrease the `count` first. If the `count` is still greater than 0, append the character to the `result` since it is not the outermost closing parenthesis.

# Complexity
- Time complexity:
The time complexity of this approach is O(n), where n is the length of the input string. This is because we iterate through the string exactly once.

- Space complexity:
The space complexity is O(n) as we store the resulting string, which in the worst case could be as large as the input string.
*/
