/*# Intuition
The problem is about checking whether a given pattern matches a sequence of words in a string. We can map each character in the pattern to a specific word in the string and vice versa. If a consistent mapping exists for the entire string, the pattern matches the string.

# Approach
1. **Splitting the String**:
   - First, split the input string `s` into individual words.
   
2. **Mapping Characters and Words**:
   - Use two maps:
     - `mp` for mapping characters from the pattern to words.
     - `mp2` for mapping words back to characters.
   - Iterate through the pattern and words simultaneously.
   - For each character in the pattern:
     - If the character already has a mapped word, check if it matches the current word.
     - If the word already has a mapped character, check if it matches the current character.
   - If any mismatch is found, return `false`.

3. **Final Check**:
   - If all checks pass, return `true`.

# Complexity
- **Time complexity**: $$O(n)$$
  - Splitting the string and checking mappings both take linear time.
- **Space complexity**: $$O(n)$$
  - Space is required for the maps and the list of words.

# Code
```cpp*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mp;  // Map for character to word
        map<string, char> mp2; // Map for word to character
        istringstream iss(s);
        vector<string> words;
        string word;
        
        // Split the string s into words
        while (iss >> word) {
            words.push_back(word);
        }

        // If pattern length is not equal to the number of words, return false
        if (pattern.size() != words.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char p = pattern[i];
            string w = words[i];

            if (mp.find(p) != mp.end()) {
                if (mp[p] != w) {
                    return false;
                }
            } else {
                mp[p] = w;
            }

            if (mp2.find(w) != mp2.end()) {
                if (mp2[w] != p) {
                    return false;
                }
            } else {
                mp2[w] = p;
            }
        }

        return true;
    }
};
