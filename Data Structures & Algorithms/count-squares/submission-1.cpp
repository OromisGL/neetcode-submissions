class CountSquares {
public:
    int mp[1001][1001] = {0};
    vector<vector<int>> plist;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
        plist.push_back(point);
    }
    
    int count(vector<int> point) {
        int dx = point[0], dy = point[1];
        int ret = 0;
        for (auto p : plist) {
            if (abs(p[0] - dx) != abs(p[1] - dy) || dx == p[0]) continue;
            ret += mp[p[0]][dy] * mp[dx][p[1]];
        }
        return ret;
    }
};
