class Solution {
  public:
    int diagonalSum(const std::vector<std::vector<int>>& matrix) {
      int size = matrix.size(), sum = 0;
      for (int row = 0; row < size; ++row) {
        sum += matrix[row][row];
        int column = size - 1 - row;
        if (row != column) {
          sum += matrix[row][column];
        }
      }
      return sum;
    }
};
