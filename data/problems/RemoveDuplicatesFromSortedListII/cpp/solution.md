### Approach

Equal values sit next to each other in a sorted list, so walk it one run of equal values at a time and keep a value only if its run has length one. With real nodes, keep a pointer to the last kept node (starting from a dummy head) and link it past any run longer than one.

### Implementation

```cpp
class Solution {
public:
    vector<int> deleteDuplicates(vector<int>& head) {
        vector<int> result;
        for (size_t i = 0; i < head.size();) {
            size_t j = i;
            while (j < head.size() && head[j] == head[i]) {
                ++j;
            }
            if (j - i == 1) {
                result.push_back(head[i]);
            }
            i = j;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides the output**.
