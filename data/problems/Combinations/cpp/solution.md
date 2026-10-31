### Approach

Backtracking. Pick numbers in increasing order, each larger than the last one picked. Stop the loop early once there aren't enough numbers left to complete the combination. Choosing in increasing order gives the lexicographic ordering for free.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        build(1, n, k, current, result);
        return result;
    }

private:
    void build(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (static_cast<int>(current.size()) == k) {
            result.push_back(current);
            return;
        }
        const int last = n - (k - static_cast<int>(current.size())) + 1;
        for (int value = start; value <= last; ++value) {
            current.push_back(value);
            build(value + 1, n, k, current, result);
            current.pop_back();
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(k * C(n, k))**.
* Space complexity: **O(k) recursion depth, besides the output**.
