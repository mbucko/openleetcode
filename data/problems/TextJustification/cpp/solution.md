### Approach

Build the lines one at a time. Greedily take words while their lengths plus one space per gap still fit. For a normal line, split the leftover spaces evenly across the gaps, with the first (leftover mod gaps) gaps getting one extra. The last line and single-word lines are joined with single spaces and padded on the right instead.

### Implementation

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> lines;
        size_t i = 0;
        while (i < words.size()) {
            size_t j = i;
            int width = 0;
            while (j < words.size() && width + static_cast<int>(words[j].size() + (j - i)) <= maxWidth) {
                width += words[j].size();
                ++j;
            }
            const int gaps = j - i - 1;
            string line;
            if (j == words.size() || gaps == 0) {
                for (size_t k = i; k < j; ++k) {
                    line += (k > i ? " " : "") + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                const int spaces = (maxWidth - width) / gaps;
                const int extra = (maxWidth - width) % gaps;
                for (size_t k = i; k + 1 < j; ++k) {
                    line += words[k] + string(spaces + (static_cast<int>(k - i) < extra ? 1 : 0), ' ');
                }
                line += words[j - 1];
            }
            lines.push_back(line);
            i = j;
        }
        return lines;
    }
};
```

### Complexity Analysis

* Time complexity: **O(total characters)**.
* Space complexity: **O(maxWidth) besides the output**.
