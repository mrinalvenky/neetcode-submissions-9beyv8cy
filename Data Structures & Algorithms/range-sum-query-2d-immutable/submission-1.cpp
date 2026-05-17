class NumMatrix {
    vector<vector<int>> prefix_;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix_.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i < prefix_.size(); i++) {
            for (int j = 1; j < prefix_[0].size(); j++) {
                prefix_[i][j] = prefix_[i-1][j] + prefix_[i][j-1] + matrix[i-1][j-1] - prefix_[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1, c1 = col1, r2 = row2 + 1, c2 = col2 + 1;
        return prefix_[r2][c2] - prefix_[r1][c2] - prefix_[r2][c1] + prefix_[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */