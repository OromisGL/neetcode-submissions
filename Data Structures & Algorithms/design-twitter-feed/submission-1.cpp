class Twitter {
public:

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<tuple<int,int,int,int>> Feed; // time, tweetid, uId, tweet Index
        unordered_set<int> users = followMap[userId];
        users.insert(userId);

        for (int u : users){
            if (tweetMap.contains(u) && !tweetMap[u].empty()) {
                int idx = tweetMap[u].size() - 1;
                Feed.push({tweetMap[u][idx].first, tweetMap[u][idx].second, u, idx});
            }
        }

        while (!Feed.empty() && res.size() < 10) {
            auto [time, tweed, uid, idx] = Feed.top();
            Feed.pop();
            res.push_back(tweed);

            if (idx > 0) {
                Feed.push({tweetMap[uid][idx - 1].first, tweetMap[uid][idx - 1].second, uid, idx - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].erase(followeeId);
    }
};
