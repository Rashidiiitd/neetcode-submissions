class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        // 1. Sort intervals by start time using a lambda comparator
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        // 2. Check for overlaps
        for (int i = 1; i < intervals.size(); i++) {
            // If the current meeting starts before the previous one ends, there is a conflict
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }

        return true;
    }
};
