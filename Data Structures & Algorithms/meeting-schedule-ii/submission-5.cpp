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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        if (n <= 1) return n;

        map<int, int> time; 

        for (const auto& interval : intervals) {
            time[interval.start]++;
            time[interval.end]--;
        }

        int maxr = 0;
        int count = 0;

        for (const auto& [tim, diff] : time) {
            maxr += diff;
            count = max(count, maxr);
        }

        return count;
    }
};
