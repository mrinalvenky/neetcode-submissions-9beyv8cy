class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int color, int origColor) {
        int ROWS = image.size(), COLS = image[0].size();
        if ((r < 0 || r >= ROWS) ||
           (c < 0 || c >= COLS) ||
           (image[r][c] != origColor)) {
            return;
        }
        image[r][c] = color;
        dfs(r + 1, c, image, color, origColor);
        dfs(r - 1, c, image, color, origColor);
        dfs(r, c + 1, image, color, origColor);
        dfs(r, c - 1, image, color, origColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (!image.size() || !image[0].size()) return image;
        if ((sr < 0 || sr >= image.size()) ||
            (sc < 0 || sc >= image[0].size())) return image;
        if (image[sr][sc] == color) return image;
        dfs(sr, sc, image, color, image[sr][sc]);
        return image;
    }
};