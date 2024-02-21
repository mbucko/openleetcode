### Approach
The solution uses the sliding window technique to efficiently along with hash map to find the length of the longest substring without repeating characters.

### Implementation

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int maxLength = 0;
        unordered_map<char, int> lastVisited;

        for (int j = 0, i = 0; j < size; j++){
            if(lastVisited[s[j]] > 0) {
                i = max(lastVisited[s[j]], i);
            }
            maxLength = max(maxLength, j - i + 1);
            lastVisited[s[j]] = j + 1;
        }
        return maxLength;
    }
};
```

### Complexity Analysis
* Time complexity : **O(n)**. We iterate over **s** exactly **n** times. Each lookup in the hash map costs only **O(1)** time.

* Space complexity : **O(k)**. We need **O(k)** space for checking a substring has no duplicate characters, where **k** is the size of the hash map. The size of the hash map is upper bounded by unique number of charasters in **s**.

