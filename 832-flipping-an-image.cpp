class Solution {
  public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& matrix) {
      for (auto& row : matrix) {
        std::reverse(row.begin(), row.end());
        for (auto& entry : row) {
          entry = 1 - entry;
        }
      }
      return matrix;
    }
};
