class Solution {
  public:
    std::string largestTimeFromDigits(const std::vector<int>& arr) {
      std::string latest_time;
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          if (i != j) {
            for (int k = 0; k < 4; ++k) {
              if (i != k && j != k) {
                for (int l = 0; l < 4; ++l) {
                  if (i != l && j != l && k != l) {
                    // arr[i] arr[j] : arr[k] arr[l]
                    if (10 * arr[i] + arr[j] <= 23 && 10 * arr[k] + arr[l] <= 59) {
                      std::string current_time;
                      current_time += '0' + arr[i];
                      current_time += '0' + arr[j];
                      current_time += ':';
                      current_time += '0' + arr[k];
                      current_time += '0' + arr[l];
                      if (latest_time.empty()) {
                        latest_time = current_time;
                      } else {
                        latest_time = std::max(latest_time, current_time);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return latest_time;
    }
};
