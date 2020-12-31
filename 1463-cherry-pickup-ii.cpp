class Solution {
  public:
    int cherryPickup(vector<vector<int>>& grid) {
      int rows = grid.size(), cols = grid[0].size();
      vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, numeric_limits<int>::min())));
      dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
      for (int row = 0; row + 1 < rows; ++row)
        for (int first_col = 0; first_col < cols; ++first_col)
          for (int first_diff = -1; first_diff <= 1; ++first_diff)
            if (0 <= first_col + first_diff && first_col + first_diff < cols)
              for (int second_col = 0; second_col < cols; ++second_col)
                for (int second_diff = -1; second_diff <= 1; ++second_diff)
                  if (0 <= second_col + second_diff && second_col + second_diff < cols)
                    dp[row + 1][first_col + first_diff][second_col + second_diff] = max(
                      dp[row + 1][first_col + first_diff][second_col + second_diff],
                      dp[row][first_col][second_col] + (
                        (first_col + first_diff == second_col + second_diff) ?
                        grid[row + 1][first_col + first_diff] :
                        grid[row + 1][first_col + first_diff] + grid[row + 1][second_col + second_diff]));
      int ans = 0;
      for (int first_col = 0; first_col < cols; ++first_col)
        for (int second_col = 0; second_col < cols; ++second_col)
          ans = max(ans, dp[rows - 1][first_col][second_col]);
      return ans;
    }
};
