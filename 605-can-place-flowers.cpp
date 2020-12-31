class Solution {
  public:
    bool canPlaceFlowers(vector<int>& f, int n) {
      int m = f.size();
      for (int i = 0; i < m; ++i) {
        if (!f[i] && 
            (i == 0 || !f[i - 1]) &&
            (i + 1 == m || !f[i + 1])) {
          f[i] = 1;
          --n;
        }
      }
      return n <= 0;
    }
};
