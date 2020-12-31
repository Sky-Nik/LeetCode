class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      vector<int> order;
      int rows = matrix.size();
      if (!rows)
        return {};
      int cols = matrix[0].size();
      int r = 0, c = 0, d = 1;
      for (int i = 0; i < rows * cols; ++i) {
        order.push_back(matrix[r][c]);
        if (d == 1) {
         if (c + d >= cols) {
            ++r;
            d = -1;
          } else if (0 > r - d){
            ++c;
            d = -1;
          } else {
            r -= d;
            c += d;
          }
        } else {
          if (r - d >= rows) {
            ++c;
            d = 1;
          } else if (c + d < 0) {
            ++r;
            d = 1;
          } else {
            r -= d;
            c += d;
          }
        }
      }
      return order;
    }
};
