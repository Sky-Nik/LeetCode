class NumArray {
  private:
    int size_;
    std::vector<int> array_, fenwick_tree_;
  
    void Increment(int index, int delta) {
      for (; index < size_; index = index | (index + 1)) {
        fenwick_tree_[index] += delta;
      }
    }
  
    int Sum(int right) {  // [0, right]
      int sum = 0;
      for (; right >= 0; right = (right & (right + 1)) - 1) {
        sum += fenwick_tree_[right];
      }
      return sum;
    }

    int Sum(int left, int right) {  // [left, right]
      return Sum(right) - Sum(left - 1);  // [left, right] = [0, right] - [0, left - 1]
    }

  public:
    NumArray(const std::vector<int>& nums) : size_(nums.size()) {
      fenwick_tree_.resize(size_);
      array_.resize(size_);
      for (int index = 0; index < size_; ++index) {
        Increment(index, nums[index]);
        array_[index] = nums[index];
      }
    }

    void update(int i, int val) {
      Increment(i, val - array_[i]);
      array_[i] = val;
    }

    int sumRange(int i, int j) {  // [i, j]
      return Sum(i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
