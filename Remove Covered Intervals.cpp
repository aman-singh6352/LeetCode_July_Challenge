class Solution {
    public:
        int removeCoveredIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), end(intervals));
            int cnt = 1;
            vector<int> interval = intervals[0];
            for(int i = 1;i < intervals.size();i++){
                int a = intervals[i][0], b = intervals[i][1];
                int c = interval[0], d = interval[1];
                if((a >= c && b <= d) || (c >= a && d <= b)){
                    interval[0] = min(a, c);
                    interval[1] = max(b, d);
                }
                else {
                    interval[0] = a;
                    interval[1] = b;
                    cnt++;
                }
            }
            return cnt;
        }
    };