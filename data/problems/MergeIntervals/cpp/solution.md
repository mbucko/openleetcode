### Approach

Sort the intervals by start. Walk through them, comparing each with the last merged interval. If it starts no later than that interval ends, they overlap, so extend the end. Otherwise start a new merged interval.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (const auto& interval : intervals) {
            if (!merged.empty() && interval[0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }
        return merged;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n log n)**.
* Space complexity: **O(n) for the output**.
