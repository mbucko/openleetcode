### Approach

Two strings are anagrams exactly when their letters, sorted, are the same. Use the sorted letters as a key in a hash map and collect the strings under their key. Then sort each group and sort the list of groups.

### Implementation

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            sort(group.begin(), group.end());
            result.push_back(move(group));
        }
        sort(result.begin(), result.end());
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n * k log k), where k is the longest string length**.
* Space complexity: **O(n * k)**.
