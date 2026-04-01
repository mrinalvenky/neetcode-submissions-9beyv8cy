class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        ROWS, COLS = len(matrix), len(matrix[0])
        self.pre_mat = [[0] * (COLS + 1) for r in range(ROWS + 1)]

        for r in range(ROWS):
            prefix = 0
            for c in range(COLS):
                prefix += matrix[r][c]
                above = self.pre_mat[r][c + 1]
                self.pre_mat[r + 1][c + 1] = prefix + above
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.pre_mat[row2 + 1][col2 + 1] - self.pre_mat[row2 + 1][col1] - self.pre_mat[row1][col2 + 1] + self.pre_mat[row1][col1]