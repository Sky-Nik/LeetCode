class Solution {
  public:
    int reachNumber(int target) {
      target = abs(target);
      int d = 0, i = 1;
      for (; d < target || (d & 1) != (target & 1); ++i)
        d += i;
      return i - 1;
    }
};
