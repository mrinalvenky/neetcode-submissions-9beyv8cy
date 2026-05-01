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
        sort(intervals.begin(), intervals.end(), 
            [](Interval& a, Interval& b) {
                return (a.start == b.start) ? (a.end < b.end) : (a.start < b.start);
            }
        );
        int prev_end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i].start) return false;
            prev_end = intervals[i].end;
        }
        return true;
    }
};
