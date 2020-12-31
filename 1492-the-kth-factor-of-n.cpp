class Solution {
  public:
    int kthFactor(int n, int k) {
      vector<int> divs;
      for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
          --k;
          if (d * d < n)
            divs.push_back(n / d);
          if (!k)
            return d;
        }
      }
      while (!divs.empty()) {
        --k;
        if (!k)
          return divs.back();
        divs.pop_back();
      }
      return -1;
    }
};
