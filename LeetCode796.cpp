class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if lengths are the same
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // Check if goal is a substring of doubled string
        return doubled.find(goal) != string::npos;
    }
};
