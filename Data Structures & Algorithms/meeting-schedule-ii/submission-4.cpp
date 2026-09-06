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

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a.start < b.start; });
        int count = 1;
        priority_queue<int, vector<int>, greater<int>> q;
        for (const auto& interval : intervals) {
            if (q.empty()) {
                q.push(interval.end);
            } else if (q.top() <= interval.start) {
                q.pop();
                q.push(interval.end);
            } else if (q.top() > interval.start) {
                q.push(interval.end);
                count++;
            }
        }

        return count;
    }
};
