class Solution {
  public:
    int prec(char c) {
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return -1;
    }
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(isalnum(ch)) {
                ans += ch;
            }
            else if(ch == '(') {
                st.push(ch);
            }
            else if(ch == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty() && st.top() != '(' &&
                     (prec(st.top()) > prec(ch) ||
                     (prec(st.top()) == prec(ch) && ch != '^'))) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};