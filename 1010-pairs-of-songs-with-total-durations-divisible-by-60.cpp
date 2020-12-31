class Solution {
  public:
    int numPairsDivisibleBy60(vector<int>& time) {
      vector<int> f(60);
      for (auto t : time)
        ++f[t % 60];
      int a = 0;
      for (int i = 0; i <= 30; ++i) {
        if (i == 0 || i == 30)
          a += (f[i] * (f[i] - 1)) >> 1;
        else 
          a += f[i] * f[60 - i];
      }
      return a;
    }
};
