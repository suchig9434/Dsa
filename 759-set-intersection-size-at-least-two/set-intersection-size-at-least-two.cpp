class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ascending; if tie, start descending
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1; // last two chosen numbers
        int result = 0;

        for (auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // Case 1: neither a nor b is inside interval → pick 2 new points
            if (b < start) {
                result += 2;
                a = end - 1;
                b = end;
            }
            // Case 2: only b is inside interval → pick 1 new point
            else if (a < start) {
                result += 1;
                a = b;
                b = end;
            }
            // Case 3: both are inside → do nothing
        }

        return result;
    }
};
