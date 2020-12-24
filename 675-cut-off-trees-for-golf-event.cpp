class Solution {
  public:
    const int kNonReachable = -1;
    std::vector<std::vector<int>> graph;
    std::vector<int> distance;
    int n_rows, n_cols;

    inline int vertex_id(int row, int col) {
      return row * n_cols + col;
    }

    int bfs_distance(int start, int target) {
      distance.assign(n_rows * n_cols, kNonReachable);
      std::deque<int> bfs = {start};
      distance[start] = 0;
      while (!bfs.empty()) {
        auto vertex = bfs.front();
        bfs.pop_front();
        if (vertex == target) {
          return distance[vertex];
        }
        for (auto adjacent : graph[vertex]) {
          if (distance[adjacent] == kNonReachable) {
            distance[adjacent] = distance[vertex] + 1;
            bfs.push_back(adjacent);
          }
        }
      }
      return kNonReachable;
    }

    int cutOffTree(const std::vector<std::vector<int>>& forest) {
      if (forest[0][0] == 0) {
        return kNonReachable;
      }

      n_rows = forest.size(), n_cols = forest[0].size();
      int n_vertex = n_rows * n_cols;
      graph.resize(n_vertex);
      distance.resize(n_vertex);
      for (int row = 0; row < n_rows; ++row) {
        for (int col = 0; col < n_cols; ++col) {
          if (forest[row][col]) {
            if (row > 0 && forest[row - 1][col]) {  // above
              graph[vertex_id(row, col)].push_back(vertex_id(row - 1, col));
            }
            if (row + 1 < n_rows && forest[row + 1][col]) {  // below
              graph[vertex_id(row, col)].push_back(vertex_id(row + 1, col));
            }
            if (col > 0 && forest[row][col - 1]) {  // left
              graph[vertex_id(row, col)].push_back(vertex_id(row, col - 1));
            }
            if (col + 1 < n_cols && forest[row][col + 1]) {  // right
              graph[vertex_id(row, col)].push_back(vertex_id(row, col + 1));
            }
          }
        }
      }

      std::vector<std::pair<int, int>> order = {{1, 0}};
      for (int row = 0; row < n_rows; ++row) {
        for (int col = 0; col < n_cols; ++col) {
          if (forest[row][col] > 1) {
            order.emplace_back(forest[row][col], vertex_id(row, col));
          }
        }
      }
      std::sort(std::next(order.begin()), order.end());

      int total_distance = 0, length = order.size();
      for (int i = 0; i + 1 < length; ++i) {
        int current_distance = bfs_distance(order[i].second, order[i + 1].second);
        if (current_distance == kNonReachable) {
          return kNonReachable;
        }
        total_distance += current_distance;
      }
      return total_distance;
    }
};
