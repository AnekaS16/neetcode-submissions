class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                if ((c == ')' && top == '(') || (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();  // Match found, pop the opening bracket
                } else {
                    return false;  // Mismatched brackets
                }
            }
        }
        return st.empty();
    }
};
