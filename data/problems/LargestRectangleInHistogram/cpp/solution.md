### Approach

Keep a stack of bars with increasing heights, each paired with the leftmost index its rectangle can start from. When a shorter bar arrives, every taller bar on the stack can't extend any further right, so pop them and measure their rectangles. The new bar takes over the start index of the last bar popped. A height-0 bar at the end flushes the stack.

### Implementation

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int best = 0;
        const int n = heights.size();
        for (int i = 0; i <= n; ++i) {
            const int h = i < n ? heights[i] : 0;
            int start = i;
            while (!stack.empty() && stack.back().second >= h) {
                const auto [index, height] = stack.back();
                stack.pop_back();
                best = max(best, height * (i - index));
                start = index;
            }
            stack.push_back({start, h});
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
