class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      int output = 0, count = 0, value = -1;
      for (auto num : nums) {
        if (num == value)
          ++count;
        else
          value = num, count = 1;
        if (count < 3)
          nums[output++] = num;
      }
      return output;
    }
};
