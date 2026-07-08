class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        int sum = 0;
        stack<int> st;
        for (int i = 0; i < n; i++ ){
            string c = tokens[i];
            if (c == "-" || c == "+" || c == "/" || c == "*") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                
                switch (*c.data()) {
                    case '-':
                        st.push(first - second);
                        break;
                    case '+':
                        st.push(first + second);
                        break;
                    case '/':
                        st.push(first / second);
                        break;
                    case '*':
                        st.push(first * second);
                        break;
                }                
            } else {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};
