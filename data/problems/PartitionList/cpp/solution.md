### Approach

Build two chains while walking the list once: one for nodes less than x and one for the rest, each appended in the order the nodes are seen. Then attach the second chain to the end of the first. With real nodes this is just relinking, using two dummy heads.

### Implementation

```cpp
class Solution {
public:
    vector<int> partition(vector<int>& head, int x) {
        vector<int> before;
        vector<int> after;
        for (const int value : head) {
            (value < x ? before : after).push_back(value);
        }
        before.insert(before.end(), after.begin(), after.end());
        return before;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra with real nodes**.
