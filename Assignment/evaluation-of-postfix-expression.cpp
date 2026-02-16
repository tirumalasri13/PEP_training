class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<long long> st;
        for (string &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else if (s == "/") {
                    if ((a < 0) ^ (b < 0) && a % b != 0)
                        res = a / b - 1;
                    else
                        res = a / b;
                }
                else if (s == "^") {
                    res = pow(a, b);
                }
                st.push(res);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};

class Solution {
  public:
    bool operators(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<double> st;
        for (int i = 0; i < n; i++) {
            if (arr[i].length() > 1 || isdigit(arr[i][0])) {
                st.push(stoi(arr[i]));
            }
            else {
                double op1 = st.top(); st.pop();
                double op2 = st.top(); st.pop();
                switch (arr[i][0]) {
                    case '+': st.push(op2 + op1); break;
                    case '-': st.push(op2 - op1); break;
                    case '*': st.push(op2 * op1); break;
                    case '/': st.push(floor(op2 / op1)); break;
                    case '^': st.push(pow(op2, op1)); break;
                }
            }
        }
        return st.top();
    }
};