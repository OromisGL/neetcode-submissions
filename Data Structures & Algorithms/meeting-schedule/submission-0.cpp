/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size(); 

        if (n < 1) return true;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){ return a.start < b.start; });

        vector<Interval> res;

        for (const auto& interval : intervals) {
            if (res.empty() || res.back().end <= interval.start) {
                res.push_back(interval);
            } else {
                return false;
            }
        }
        return true;
    }
};
