struct RMQ {
  int length = 0;
  std::vector<int> block_min, array;

  void Clear() {
    length = 0;
    block_min.clear();
    array.clear();
  }

  void Initialize(const std::vector<int>& a) {
    int n = a.size();
    array.resize(n);
    length = sqrt(n + .0) + 1;
    block_min.resize(length);
    for (int block_id = 0; block_id < length; ++block_id) {
      block_min[block_id] = block_id * length;
    }
    for (int i = 0; i < n; ++i) {
      const int block_id = i / length;
      if (a[block_min[block_id]] > a[i]) {
        block_min[block_id] = i;
      }
      array[i] = a[i];
    }
  }

  int MinIndex(int left, int right) {
    int answer = left;
    for (int i = left; i < right; ) {
      if (i % length == 0 && i + length <= right) {
        const int block_id = i / length;
        if (array[answer] > array[block_min[block_id]]) {
          answer = block_min[block_id];
        }
        i += length;
      } else {
        if (array[answer] > array[i]) {
          answer = i;
        }
        ++i;
      }
    }
    return answer;
  }
} rmq;

class Solution {
  public:
    int largestRectangleArea(vector<int>& heights, int left = -1, int right = -1) {
      if (left == -1 && right == -1) {
        rmq.Clear();
        rmq.Initialize(heights);
        left = 0;
        right = heights.size();
      }
      if (left >= right)
        return 0;
      int min_index = rmq.MinIndex(left, right);
      // cout << left << " " << min_index << " " << right << "\n";
      return max(heights[min_index] * (right - left), 
                 max(largestRectangleArea(heights, left, min_index),
                     largestRectangleArea(heights, min_index + 1, right)));
    }
};
