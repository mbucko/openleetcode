### Approach

Start with the two outermost walls, the widest container possible. The shorter wall limits the water, and moving the taller wall inwards can never help, because the width shrinks and the height is still capped by the shorter wall. So always move the shorter wall inwards, and track the best area along the way.

### Implementation

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int best = 0;
        while (left < right) {
            best = max(best, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
