class Solution {
  public:
    bool validMountainArray(const std::vector<int>& array) {
      int length = array.size();
      if (length < 3) return false;
      bool increasing = true;
      for (int index = 0; index + 1 < length; ++index) {
        if (array[index] == array[index + 1]) {
          return false;
        } else if (array[index] < array[index + 1]) {
          if (!increasing) return false;
        } else {  // if (array[index] > array[index + 1])
          increasing = false;
        }
      }
      return array[0] < array[1] && array[length - 2] > array[length - 1];
    }
};
