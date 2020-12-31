class Solution {
  public:
    int LIS(vector<int>& a) {
      int len = a.size();
      vector<int64_t> dp(len + 1, numeric_limits<int64_t>::max());
      dp[0] = numeric_limits<int64_t>::min();
      for (int i = 0; i < len; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), a[i]);
        int j = distance(dp.begin(), it);
        if (dp[j - 1] < a[i] && a[i] < dp[j])
          dp[j] = a[i];
      }
      for (auto el : dp) {
        cout << el << " ";
      }
      cout << "\n";
      auto it = lower_bound(dp.begin(), dp.end(), numeric_limits<int64_t>::max());
      return distance(dp.begin(), it);
    }

    bool increasingTriplet(vector<int>& nums) {
      return LIS(nums) > 3;
    }
};
