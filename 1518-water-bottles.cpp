class Solution {
  public:
    int numWaterBottles(int initial, int exchange) {
      int drunk = 0, full = initial, empty = 0;
      while (full) {
        drunk += full;
        empty += full;
        full = 0;
        full += empty / exchange;
        empty %= exchange;
      }
      return drunk;
    }
};
