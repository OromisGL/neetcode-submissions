/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*,Node*> copy;

    void bfs(Node* node) {
        copy[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* n : curr->neighbors) {
                if (!copy.contains(n)) {
                    copy[n] = new Node(n->val);
                    q.push(n);
                }
                copy[curr]->neighbors.push_back(copy[n]);
            }
        }

    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        bfs(node);
        return copy[node];
        
    }
};
