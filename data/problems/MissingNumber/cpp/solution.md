### Approach

The numbers 0 to n add up to n(n + 1) / 2. Subtracting every value in the array from that total leaves the missing one.

### Implementation

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (const int num : nums) {
            sum -= num;
        }
        return sum;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
