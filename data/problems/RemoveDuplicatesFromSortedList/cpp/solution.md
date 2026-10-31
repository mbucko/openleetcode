### Approach

Walk the list once. A node whose value equals the previous kept node's value is a duplicate and is skipped. With real nodes, that means linking the current node straight to the following one.

### Implementation

```cpp
class Solution {
public:
    vector<int> deleteDuplicates(vector<int>& head) {
        vector<int> result;
        for (const int value : head) {
            if (result.empty() || result.back() != value) {
                result.push_back(value);
            }
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides the output**.
