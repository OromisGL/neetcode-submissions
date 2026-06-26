class Solution {
public:

    string encode(vector<string>& strs) {
        string msg;

        for (const string& s : strs){
            msg += to_string((int)s.size()) + '#' + s;
        }
        return msg;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> liste;
        int i = 0;

        while (i < n) {
            int j = i;
            while ( j < n && s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            string w = s.substr(j + 1, len);
            liste.push_back(w);
            i = j + 1 + len;
        }
        return liste;
    }
};
