class Solution {
  public:
    string decodeAtIndex(string s, int k) {
      int64_t l = 0;
      for (auto ch : s) {
        if ('0' <= ch && ch <= '9') {
          int ol = l;
          l *= ch - '0';
          if (l >= k) {
            k %= ol;
            if (!k)
              k = ol;
            return decodeAtIndex(s, k);
          }
        } else {
          ++l;
          if (l == k)
            return string(1, ch);
        }
      }
      throw logic_error("s length is too small");
    }
};
