class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);

        // Count occurrences of characters in string s
        for (char ch : s) {
            count[ch - 'a']++;
        }

        // Subtract occurrences of characters in string t
        for (char ch : t) {
            count[ch - 'a']--;
        }

        int steps = 0;

        // Calculate the total number of steps needed
        for (int c : count) {
            steps += abs(c);
        }

        return steps / 2;  // Divide by 2 because each step involves replacing one character
    }
};