class Solution {
  public:
    auto diagonalSort(std::vector<std::vector<int>>& matrix) {
      std::vector<std::vector<int>> diagonals;
      int row_count = matrix.size(), column_count = matrix[0].size();
      for (int row = 0; row < row_count; ++row) {
        diagonals.emplace_back();
        int k = 0;
        while (row + k < row_count && k < column_count) {
          diagonals.back().push_back(matrix[row + k][k]);
          ++k;
        }
      }
      for (int column = 1; column < column_count; ++column) {
        diagonals.emplace_back();
        int k = 0;
        while (k < row_count && column + k < column_count) {
          diagonals.back().push_back(matrix[k][column + k]);
          ++k;
        }
      }
      for (auto& diagonal : diagonals) {
        std::sort(diagonal.begin(), diagonal.end());
      }
      int diagonal_index = 0;
      for (int row = 0; row < row_count; ++row, ++diagonal_index) {
        int k = 0;
        while (row + k < row_count && k < column_count) {
          matrix[row + k][k] = diagonals[diagonal_index][k];
          ++k;
        }
      }
      for (int column = 1; column < column_count; ++column, ++diagonal_index) {
        int k = 0;
        while (k < row_count && column + k < column_count) {
          matrix[k][column + k] = diagonals[diagonal_index][k];
          ++k;
        }
      }
      return matrix;
    }
};
