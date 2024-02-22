### Approach

Iterate through the array once. For each element, check if the target minus the current element exists in the hash table. If it does, we have found a valid pair of numbers. If not, we add the current element to the hash table.

### Implementation

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> visited;

        for (int i = 0; i < nums.size(); ++i) {
            const int curElement = nums[i];
            const int delta = target - curElement;
            
            const auto it = visited.find(delta);
            if (it != visited.end()) {
                return {it->second, i};
            }
            
            visited.insert({curElement, i});
            continue;

        }
        return {};
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.<br>
We traverse the **nums** containing **n** elements only once. Each lookup in the hash map costs only **O(1)** time.

* Space complexity: **O(n)**.<br>
The extra space that is required depends on the number of items stored in the hash map. In this case it's **n** elements.