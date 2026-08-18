class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int total{n * n};
        int row{0}, col{0};
        // right 0 , 1
        // down 1, 0
        // left 0, -1
        // up -1, -1
        int row_incr = 0;
        int col_incr = 1;
        for (auto i{1}; i <= total; ++i) {
            matrix[row][col] = i;
            int next_row = row + row_incr;
            int next_col = col + col_incr;
            if(not_valid_cell(next_row, next_col, n, matrix)) {
                // change direction.
                int tmp = row_incr;
                row_incr = col_incr;
                col_incr = -tmp;
            }
            row += row_incr;
            col += col_incr;
        }
        return matrix;
    }

    bool not_valid_cell(int row, int col, int border,
         std::vector<std::vector<int>> const& matrix) {
            return row < 0 || row >= border || col < 0 || col >= border || matrix[row][col] != 0;
        }
};