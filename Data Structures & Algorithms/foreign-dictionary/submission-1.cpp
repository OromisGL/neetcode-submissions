class Solution {
public:

    int uncommon(string& s1, string& s2) {
        for (int i = 0; i < s1.size() && i < s2.size(); i++) {
            if (s1[i] != s2[i]) {
                return i;
            }
        }
        return -1;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDeg;

        for (const string& w : words) {
            for (const char c : w) {
                inDeg[c] = 0;
            }
        }

        for (int i = 0; i < n - 1; i ++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            if (w1.size() > w2.size() && w1.substr(0,len) == w2.substr(0,len)) return "";
            int pos = uncommon(w1, w2);
            if (pos == -1) continue;

            if (!adj[w1[pos]].contains(w2[pos])){
                adj[w1[pos]].insert(w2[pos]);
                inDeg[w2[pos]]++;
            }
        }

        queue<char> q;

        for (const auto& [ch, count] : inDeg) {
            if (count == 0) q.push(ch);
        }

        string order;

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char c : adj[curr]) {
                inDeg[c]--;
                if (inDeg[c] == 0) {
                    q.push(c);
                }
            }
        }
        

        return order.size() ==  adj.size() ? order : ""; 
    }
};
