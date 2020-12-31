class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> m(n, vector<int>(n));
      int r = 0, c = 0, dr = 0, dc = 1;
      for (int i = 0; i < n * n; ++i) {
        m[r][c] = i + 1;
        if (0 > r + dr || r + dr >= n ||
            0 > c + dc || c + dc >= n ||
            m[r + dr][c + dc])
          std::tie(dc, dr) = std::make_pair(-dr, dc);
        r += dr;
        c += dc;
      }
      return m;
    }
};
