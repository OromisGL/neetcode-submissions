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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*,Node*> copy;
        queue<Node*> q;

        q.push(node);
        copy[node] = new Node(node->val);

        while (!q.empty()){
            Node* curr = q.front();
            q.pop();

            for (Node* n : curr->neighbors) {
                if (!copy.contains(n)) {
                    q.push(n);
                    copy[n] = new Node(n->val);
                }
                copy[curr]->neighbors.push_back(copy[n]);
            }
        }
        return copy[node];
    }
};
