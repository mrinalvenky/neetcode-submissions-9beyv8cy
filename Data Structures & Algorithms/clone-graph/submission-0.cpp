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
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node *old_node = q.front();
            q.pop();
            Node *new_node = new Node(old_node->val);
            mp[old_node] = new_node;
            for (int i = 0; i < old_node->neighbors.size(); i++) {
                if (!mp.count(old_node->neighbors[i])) {
                    q.push(old_node->neighbors[i]);
                }
            }
        }
        for(auto& [old, nd] : mp) {
            for (int i = 0; i < old->neighbors.size(); i++) {
                nd->neighbors.push_back(mp[old->neighbors[i]]);
            }
        }
        return mp[node];
    }
};
