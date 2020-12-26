struct PairHasher {
  size_t operator() (const std::pair<int, int>& pair) const {
    return pair.first | (pair.second << 16);
  }
};

class Solution {
  public:
    int minAreaRect(std::vector<std::vector<int>>& points) {
      std::sort(points.begin(), points.end());
      std::unordered_map<std::pair<int, int>, int, PairHasher> y_pair_x_coordinate;
      int current_x = -1;
      int min_area = std::numeric_limits<int>::max();
      std::vector<int> current_x_points;
      for (auto point : points) {
        if (point[0] == current_x) {
          for (auto current_x_point : current_x_points) {
            std::pair<int, int> current_y_pair(current_x_point, point[1]);
            if (y_pair_x_coordinate.count(current_y_pair)) {
              int current_area = (current_x - y_pair_x_coordinate[current_y_pair]) * (point[1] - current_x_point);
              min_area = std::min(min_area, current_area);
            }
            y_pair_x_coordinate[current_y_pair] = current_x;
          }
        } else {
          current_x_points.clear();
          current_x = point[0];
        }
        current_x_points.emplace_back(point[1]);
      }
      // return min_area == std::numeric_limits<int>::max() ? 0 : min_area;
      if (min_area == std::numeric_limits<int>::max()) {
        return 0;
      } else {
        return min_area;
      }
    }
};
