class Solution {
  public:
    int maxCoins(vector<int>& nums) {
      int len = nums.size();
      vector<vector<int>> dp(len, vector<int>(len, 0));
      for (int diff = 0; diff < len; ++diff)
        for (int left = 0, right = diff; right < len; ++left, ++right)
          for (int burst = left; burst <= right; ++burst) {
            dp[left][right] = max(dp[left][right], 
              (left == 0 ? 1 : nums[left - 1]) * nums[burst] * (right == len - 1 ? 1 : nums[right + 1]) +
              (burst == left ? 0 : dp[left][burst - 1]) + (burst == right ? 0 : dp[burst + 1][right]));
          }
      return dp[0][len - 1];
    }
};
