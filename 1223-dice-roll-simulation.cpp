class Solution {
  public:
    const int mod = 1'000'000'007;
    int dieSimulator(int n, const std::vector<int>& roll_max) {
      std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(6));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
          dp[i][j].resize(roll_max[j]);
        }
      }
      for (int i = 0; i < 6; ++i) {
        dp[0][i][0] = 1;
      }
      for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < 6; ++j) {
          for (int k = 0; k < roll_max[j]; ++k) {
            for (int l = 0; l < 6; ++l) {
              if (l == j) {
                if (k + 1 < roll_max[j]) {
                  dp[i + 1][j][k + 1] += dp[i][j][k];
                  if (dp[i + 1][j][k + 1] >= mod) {
                    dp[i + 1][j][k + 1] -= mod;
                  }
                }
              } else {
                dp[i + 1][l][0] += dp[i][j][k];
                if (dp[i + 1][l][0] >= mod) {
                  dp[i + 1][l][0] -= mod;
                }
              } 
            }
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < roll_max[i]; ++j) {
          ans += dp[n - 1][i][j];
          if (ans >= mod) {
            ans -= mod;
          }
        }
      }
      return ans;
    }
};
