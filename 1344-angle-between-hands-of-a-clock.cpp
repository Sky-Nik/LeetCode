class Solution {
  public:
    double angleClock(int hour, int minute) {
      double hour_angle = 30 * hour + minute / 2.;
      double minute_angle = 6 * minute;
      double max_angle = std::max(hour_angle, minute_angle);
      double min_angle = std::min(hour_angle, minute_angle);
      double first_angle = max_angle - min_angle;
      double second_angle = 360 + min_angle - max_angle;
      return std::min(first_angle, second_angle);
    }
};
