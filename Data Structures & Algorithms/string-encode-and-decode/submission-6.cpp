class Solution {
public:

    string encode(vector<string>& strs) {
        string code;
        for (const string& s : strs){
            code += to_string(s.size()) + '#' + s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> str;
        int n = s.size();
        int i = 0; 

        while (i < n){
            int j = i;
            while (s[j] !='#') j++;
            int len = stoi(s.substr(i,j-i));
            str.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return str;
    }
};
