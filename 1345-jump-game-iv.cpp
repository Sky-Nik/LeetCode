class Solution {
  public:
    int minJumps(vector<int>& a) {
      int n = a.size();
      unordered_map<int, set<pair<int, int>>> graph;
      for (int i = 0; i < n; ++i) {
        if (i > 0)
          graph[i].emplace(i - 1, 2);
        if (i + 1 < n)
          graph[i].emplace(i + 1, 2);
        graph[1e9-a[i]].emplace(i, 1);
        graph[i].emplace(1e9-a[i], 1);
      }
      unordered_map<int, int> distances;
      priority_queue<pair<int, int>,
                     vector<pair<int, int>>,
                     greater<pair<int, int>>> dijkstra;
      dijkstra.emplace(0, 0);
      distances[0] = 0;
      while (!dijkstra.empty()) {
        auto [dv, v] = dijkstra.top();
        dijkstra.pop();
        if (v == n - 1)
          return (1 + dv) >> 1;
        if (distances[v] == dv) {
          for (auto [w, dvw] : graph[v]) {
            if (!distances.count(w) || distances[w] > dv + dvw) {
              dijkstra.emplace(dv + dvw, w);
              distances[w] = dv + dvw;
            }
          }
        }
      }
      return -1;
    }
};
