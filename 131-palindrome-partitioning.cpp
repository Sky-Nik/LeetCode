class Solution {
  public:
    vector<vector<string>> partition(string s) {
      if (s.empty()) {
        return {{}};
      }
      vector<vector<string>> answer;
      auto t = s;
      reverse(t.begin(), t.end());
      if (t == s) {
        answer.emplace_back();
        answer.back().push_back(s);
      }
      int l = s.length();
      for (int i = 1; i < l; ++i) {
        auto ss = s.substr(0, i);
        t = ss;
        reverse(t.begin(), t.end());
        if (t == ss) {
          for (auto partial_answer : partition(s.substr(i))) {
            answer.emplace_back();
            answer.back().push_back(ss);
            copy(partial_answer.begin(), partial_answer.end(), back_inserter(answer.back()));
          }
        }
      }
      return answer;
    }
};
