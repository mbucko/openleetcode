class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int start = newInterval[0];
        int end = newInterval[1];
        size_t i = 0;
        while (i < intervals.size() && intervals[i][1] < start) {
            result.push_back(intervals[i++]);
        }
        while (i < intervals.size() && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            ++i;
        }
        result.push_back({start, end});
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        return result;
    }
};