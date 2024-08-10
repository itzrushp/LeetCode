class Solution {
public:
    bool checkValidString(string s) {
        // Using a Greedy Approach to maintain a range of possible open parentheses counts
        int minOpen = 0;  // Minimum number of open parentheses that must be balanced
        int maxOpen = 0;  // Maximum number of open parentheses that could be balanced
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {  // '*' can be treated as '(', ')' or ''
                minOpen--;
                maxOpen++;
            }
            // Ensure minOpen doesn't go negative
            if (minOpen < 0) minOpen = 0;
            // If maxOpen is negative, too many closing parentheses were encountered
            if (maxOpen < 0) return false;
        }
        
        // If minOpen is 0, a valid string can be formed
        return minOpen == 0;
    }
};
/*
### Dry Run

Let's take the input string `s = "(*))"` and walk through the solution step by step.

#### Initial State:
- `minOpen = 0` (minimum number of open parentheses needed)
- `maxOpen = 0` (maximum number of open parentheses possible)

#### Iteration 1:
- **Character**: `'('`
  - **Action**: Increment both `minOpen` and `maxOpen`
  - **State**: `minOpen = 1`, `maxOpen = 1`

#### Iteration 2:
- **Character**: `'*'`
  - **Action**: `'*'` can be `(`, `)`, or an empty string, so decrement `minOpen` by 1 and increment `maxOpen` by 1
  - **State**: `minOpen = 0` (because it can't go negative), `maxOpen = 2`

#### Iteration 3:
- **Character**: `')'`
  - **Action**: Decrement both `minOpen` and `maxOpen`
  - **State**: `minOpen = -1` (but we adjust it back to 0 because it can't be negative), `maxOpen = 1`

#### Iteration 4:
- **Character**: `')'`
  - **Action**: Decrement both `minOpen` and `maxOpen`
  - **State**: `minOpen = -1` (adjust back to 0), `maxOpen = 0`

#### Final Check:
- `minOpen = 0` (means all open parentheses can be matched), so the string is valid.

### Conclusion
Since `minOpen` ends up being 0, the string can be balanced and is a valid parentheses string.

# Intuition
The problem involves determining whether a string of parentheses and wildcard characters (`*`) can be made valid. Since `*` can represent `(`, `)`, or an empty string, the challenge lies in balancing these possibilities.

# Approach
- **Greedy Approach:** 
  - Maintain a range of possible open parentheses counts (`minOpen` and `maxOpen`).
  - As we iterate through the string:
    - For each `(`, increment both `minOpen` and `maxOpen`.
    - For each `)`, decrement both `minOpen` and `maxOpen`.
    - For each `*`, decrement `minOpen` and increment `maxOpen`.
    - Ensure `minOpen` does not go negative, and if `maxOpen` becomes negative, return `false`.
  - After processing the string, if `minOpen` is 0, the string is valid.

# Complexity
- **Time complexity:** $$O(n)$$, where `n` is the length of the string.
- **Space complexity:** $$O(1)$$, since we are only using a few extra variables.

  */
