class Solution {
  public:
    bool buddyStrings(const std::string& first, const std::string& second) {
      if (first.size() != second.size()) {
        return false;
      }

      int first_different_position = -1, second_different_position = -1, length = first.size();
      for (int index = 0; index < length; ++index) {
        if (first[index] != second[index]) {
          if (first_different_position == -1) {
            first_different_position = index;
          } else if (second_different_position == -1) {
            second_different_position = index;
          } else {
            return false;
          }
        }
      }
      
      if (first_different_position == -1) {
        std::unordered_map<char, int> counter;
        for (auto letter : first) {
          ++counter[letter];
          if (counter[letter] == 2) {
            return true;
          }
        }
        return false;
      } else if (second_different_position == -1) {
        return false;
      } 

      return first[first_different_position] == second[second_different_position] &&
             first[second_different_position] == second[first_different_position];
    }
};
