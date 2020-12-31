class Solution {
  public:
    int smallestRangeII(vector<int>& a, int k) {
      sort(a.begin(), a.end());
      int n = a.size();
      int ans = a[n - 1] - a[0];
      for (int i = 0; i + 1 < n; ++i) {
        a[i] += k << 1;
        ans = min(ans, max(a[n - 1], a[i]) - min(a[0], a[i + 1]));
      }
      return ans;
    }
};
