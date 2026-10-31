### Approach

Insert each value into a hash set. If a value is already in the set, it is a duplicate.

### Implementation

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (const int num : nums) {
            if (!seen.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
