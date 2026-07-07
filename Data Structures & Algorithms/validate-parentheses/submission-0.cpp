class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> oc = {{')', '('}, {'}', '{'}, {']', '['}};

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            if (oc.contains(s[i])) {
                if (st.empty() || oc[s[i]] != st.top()) return false;
                st.pop();
            } 
        }

        return st.empty();
    }
};
