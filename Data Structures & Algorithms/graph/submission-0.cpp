class Graph {
public:

    unordered_map<int, unordered_set<int>> adj;

    Graph() { }

    void addEdge(int src, int dst) {
        adj[src].insert(dst);

        if (adj.find(dst) == adj.end()) {
            adj[dst] = {};
        }
    }

    bool removeEdge(int src, int dst) {
        if (!adj.contains(src)) return false;

        for (int i : adj[src]) {
            if (i == dst) {
                adj[src].erase(i);
                return true;
            }
        }
        return false;
    }

    bool hasPath(int src, int dst) {
        if (!adj.contains(src)) return false;

        queue<int> q;
        unordered_set<int> vis;
        q.push(src);
        vis.insert(src);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == dst) return true;

            for (int i : adj[curr]) {
                if (vis.find(i) == vis.end()) {
                    vis.insert(i);
                    q.push(i);
                }
            }
        }
        return false;
    }
};
