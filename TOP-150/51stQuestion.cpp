class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                brackets.push(ch);
            } else {
                if (brackets.empty() || brackets.top() != mapping[ch]) {
                    return false;
                }
                brackets.pop();
            }
        }

        return brackets.empty();
    }
};