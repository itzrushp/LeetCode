/*# Intuition
We want to find how many words are consistent with a set of allowed characters. A word is considered consistent if all its characters are part of the allowed characters. A straightforward way to do this efficiently is to use bit manipulation to represent the allowed characters and words as bitmasks, which allows for quick subset checks.

# Approach
1. **Bitmask Representation of Allowed Characters:**
   - We can represent the allowed characters using a bitmask where each bit corresponds to a character ('a' to 'z'). If a character is allowed, the corresponding bit will be set to `1`, otherwise it will remain `0`.

2. **Bitmask Representation of Each Word:**
   - For each word, we create a similar bitmask that represents the characters present in the word.

3. **Subset Check:**
   - For a word to be consistent with the allowed characters, the bitmask of the word must be a subset of the bitmask of the allowed characters. This can be checked by using a bitwise AND operation: if `(wordMask & allowedMask) == wordMask`, it means all characters in the word are allowed.

4. **Count the Consistent Words:**
   - For each word, if it satisfies the condition, we increment the count.

# Dry Run

#### Example:
- **Input:**
  - Allowed: `"ab"`
  - Words: `["ad", "bd", "aaab", "baa", "badab"]`
  
1. **Bitmask for Allowed Characters:**
   - `"ab"` translates to a bitmask:
     - For 'a', set the 0th bit: `1 << (0)` = `0001`
     - For 'b', set the 1st bit: `1 << (1)` = `0010`
     - So, `allowedMask = 0001 | 0010 = 0011` (binary), or `3` in decimal.

2. **Processing Each Word:**
   - `"ad"`:
     - 'a' corresponds to `1 << (0) = 0001`
     - 'd' corresponds to `1 << (3) = 1000`
     - `wordMask = 0001 | 1000 = 1001` (binary), or `9` in decimal.
     - Check: `allowedMask & wordMask = 0011 & 1001 = 0001`, which is not equal to `wordMask`, so it's not consistent.
   
   - `"bd"`:
     - 'b' corresponds to `1 << (1) = 0010`
     - 'd' corresponds to `1 << (3) = 1000`
     - `wordMask = 0010 | 1000 = 1010` (binary), or `10` in decimal.
     - Check: `allowedMask & wordMask = 0011 & 1010 = 0010`, which is not equal to `wordMask`, so it's not consistent.
   
   - `"aaab"`:
     - 'a' corresponds to `1 << (0) = 0001`
     - 'b' corresponds to `1 << (1) = 0010`
     - `wordMask = 0001 | 0010 = 0011` (binary), or `3` in decimal.
     - Check: `allowedMask & wordMask = 0011 & 0011 = 0011`, which equals `wordMask`, so it's consistent.

   - `"baa"`:
     - Same bitmask as `"aaab"`, so it's consistent.

   - `"badab"`:
     - 'b' corresponds to `1 << (1) = 0010`
     - 'a' corresponds to `1 << (0) = 0001`
     - 'd' corresponds to `1 << (3) = 1000`
     - `wordMask = 0010 | 0001 | 1000 = 1011` (binary), or `11` in decimal.
     - Check: `allowedMask & wordMask = 0011 & 1011 = 0011`, which is not equal to `wordMask`, so it's not consistent.

3. **Result:** There are 2 consistent words (`"aaab"` and `"baa"`).

# Complexity
- **Time Complexity:**  
  - Building the `allowedMask` takes \(O(n)\), where \(n\) is the length of the allowed string.
  - For each word, creating its bitmask and checking the subset condition takes \(O(m)\), where \(m\) is the length of the word. Processing all words takes \(O(k \cdot m)\), where \(k\) is the number of words and \(m\) is their average length.
  - So, the overall time complexity is \(O(n + k \cdot m)\).

- **Space Complexity:**  
  - We use a few integers for bitmask storage, so the space complexity is \(O(1)\).*/

# Code
```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Create a bitmask for the allowed characters
        int allowedMask = 0;
        
        for (char c : allowed) {
            allowedMask |= (1 << (c - 'a'));  // Set the corresponding bit for each allowed character
        }
        
        int ans = 0;
        
        // Step 2: Process each word in the words list
        for (string word : words) {
            int wordMask = 0;
            
            // Step 3: Create a bitmask for the current word
            for (char c : word) {
                wordMask |= (1 << (c - 'a'));  // Set the bit for each character in the word
            }
            
            // Step 4: Check if the wordMask is a subset of allowedMask
            if ((wordMask & allowedMask) == wordMask) {
                ans++;
            }
        }
        
        return ans;  // Return the number of consistent strings
    }
};
