/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int n, int r, int c) {
        bool is_same = true;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                if (grid[r][c] != grid[r + i][c + j]) is_same = false;
            }
        }
        if (is_same) return new Node(grid[r][c], true);
        int new_size = static_cast<int>(n / 2);
        Node *tl = helper(grid, new_size, r, c);
        Node *tr = helper(grid, new_size, r, c + new_size);
        Node *bl = helper(grid, new_size, r + new_size, c);
        Node *br = helper(grid, new_size, r + new_size, c + new_size);
        return new Node(grid[r][c], false, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, grid.size(), 0, 0);  
    }
};