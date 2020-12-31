class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums) {
      auto it = lower_bound(nums.begin(), nums.end(), 0);
      auto d = distance(nums.begin(), it);
      vector<int> output;
      int l = d - 1, r = d, len = nums.size();
      while (l >= 0 || r < len) {
        if (l >= 0 && r < len) {
          if (nums[l] * nums[l] > nums[r] * nums[r]) {
            output.push_back(nums[r] * nums[r]);
            ++r;
          } else {
            output.push_back(nums[l] * nums[l]);
            --l;
          }
        } else if (l >= 0) {
            output.push_back(nums[l] * nums[l]);
            --l;
        } else {
            output.push_back(nums[r] * nums[r]);
            ++r;
        }
      }
      return output;
    }
};
