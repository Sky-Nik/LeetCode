class Solution {
  public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
      unordered_map<int, int> ab;
      for (auto ai : a)
        for (auto bj : b)
          ++ab[ai + bj];
      
      unordered_map<int, int> cd;
      for (auto ci : c)
        for (auto dj : d)
          ++cd[ci + dj];
      
      int ans = 0;
      for (auto [k, v] : ab)
        ans += cd[-k] * v;
      return ans;
    }
};
