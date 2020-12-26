class Solution {
  public:
    int minSteps(const std::string& initial, const std::string& target) {
      std::unordered_map<char, int> frequency;
      for (auto letter : initial) {
        ++frequency[letter];
      }
      for (auto letter : target) {
        --frequency[letter];
      }
      int steps = 0;
      for (auto [letter, difference] : frequency) {
        if (difference > 0) {
          steps += difference;
        }
      }
      return steps;
    }
};
