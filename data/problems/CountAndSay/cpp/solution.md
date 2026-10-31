### Approach

Start from "1" and build each term from the previous one. Scan the previous term, find each run of equal digits, and append the run's length followed by the digit.

### Implementation

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string term = "1";
        for (int step = 1; step < n; ++step) {
            string next;
            for (size_t i = 0; i < term.size();) {
                size_t j = i;
                while (j < term.size() && term[j] == term[i]) {
                    ++j;
                }
                next += to_string(j - i) + term[i];
                i = j;
            }
            term = move(next);
        }
        return term;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n * L), where L is the length of the longest term**.
* Space complexity: **O(L)**.
