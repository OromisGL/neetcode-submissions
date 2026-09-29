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
            int x = p[0], y = p[1];
            if (abs(x - dx) != abs(y - dy) || dx == x) continue;
            ret += mp[x][dy] * mp[dx][y];
        }
        return ret;
    }
};
