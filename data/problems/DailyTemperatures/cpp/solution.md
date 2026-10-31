### Approach

Keep a stack of indices that have not found a warmer day yet. Their temperatures never increase from the bottom of the stack to the top. When a warmer day arrives, pop every colder index and record how far away the warmer day is.

### Implementation

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        vector<int> stack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                answer[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return answer;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
