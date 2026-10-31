### Approach

Keep a min-heap holding the current front value of each list. Repeatedly pop the smallest value, append it to the result, and push the next value from the same list. The heap never holds more than k entries.

### Implementation

```cpp
class Solution {
public:
    vector<int> mergeKLists(vector<vector<int>>& lists) {
        using Entry = tuple<int, size_t, size_t>;
        priority_queue<Entry, vector<Entry>, greater<Entry>> heap;
        for (size_t i = 0; i < lists.size(); ++i) {
            if (!lists[i].empty()) {
                heap.emplace(lists[i][0], i, 0);
            }
        }
        vector<int> merged;
        while (!heap.empty()) {
            const auto [value, i, j] = heap.top();
            heap.pop();
            merged.push_back(value);
            if (j + 1 < lists[i].size()) {
                heap.emplace(lists[i][j + 1], i, j + 1);
            }
        }
        return merged;
    }
};
```

### Complexity Analysis

* Time complexity: **O(N log k), where N is the total number of nodes**.
* Space complexity: **O(k) for the heap, besides the output**.
