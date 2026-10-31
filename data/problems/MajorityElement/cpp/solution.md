### Approach

Boyer-Moore voting: keep a candidate and a counter. A matching value adds a vote and any other value removes one. When the counter hits zero, take the next value as the new candidate. The majority value appears more often than all the others combined, so it is the candidate at the end.

### Implementation

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (const int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
