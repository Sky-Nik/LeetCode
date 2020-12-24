class Solution {
  public:
    std::string mostCommonWord(std::string& paragraph, const std::vector<std::string>& banned) {
      std::unordered_set<std::string> banned_set(banned.begin(), banned.end());
      std::unordered_map<std::string, int> counter;
      std::string current_word;
      paragraph += '$';
      for (auto ch : paragraph) {
        ch = std::tolower(ch);
        if ('a' <= ch && ch <= 'z') {
          current_word += ch;
        } else {
          if (!current_word.empty() && !banned_set.count(current_word)) {
            ++counter[current_word];
          }
          current_word = "";
        }
      }
      return std::max_element(counter.begin(), counter.end(), 
                              [] (const std::pair<std::string, int>& first, const std::pair<std::string, int>& second) -> bool {
                                return first.second < second.second;
                              })->first;
    }
};
