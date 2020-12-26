class MyCalendarTwo {
  public:
    bool book(int start, int end) {
      ++events_[start + .1], --events_[end - .1];
      int current_event_count = 0;
      for (auto [time, count] : events_) {
        current_event_count += count;
        if (start <= time && time <= end && current_event_count > 2) {
          --events_[start + .1], ++events_[end - .1];
          return false;
        }
      }
      return true;
    }

  std::map<float, int> events_;  // value = number of events starting or ending at the given time
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
