class Solution {
  public:
    Solution(const std::vector<int>& nums) {
      int length = nums.size();
      for (int index = 0; index < length; ++index) {
        positions_[nums[index]].push_back(index);
      }
    }
    
    int pick(int target) {
      std::uniform_int_distribution<int> distribution(0, positions_[target].size() - 1);
      return positions_[target][distribution(generator_)];
    }

  private:
    std::mt19937 generator_;
    std::unordered_map<int, std::vector<int>> positions_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
