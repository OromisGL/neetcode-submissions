class TimeMap {
public:

    unordered_map<string, vector<pair<int,string>>> timeMap; // key, value: (index == timestamp; value for given time)

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!timeMap.contains(key) || timeMap[key].size() == 0) return "";

        int left = 0;
        int right = timeMap[key].size() - 1;
        string res = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (timestamp >= timeMap[key][mid].first) {
                res = timeMap[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
