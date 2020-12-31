class Solution {
  public:
    int numDecodings(string s) {
      int n = s.length();
      vector<int> dp(n + 1);
      dp[0] = 1;
      for (int i = 0; i < n; ++i) {
        if (s[i] != '0') {
          dp[i + 1] += dp[i];
        }
        if (i > 0) {
          int k = 10 * (s[i - 1] - '0') + (s[i] - '0');
          if (10 <= k && k <= 26) {
            dp[i + 1] += dp[i - 1];
          }
        }
      }
      return dp[n];
    }
};
