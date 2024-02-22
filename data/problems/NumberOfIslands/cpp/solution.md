### Approach

Perform a linear scan of the 2D grid map. If a node contains a '1', it is considered a root node that initiates a Breadth First Search. Add this node to a queue and change its value to '0' to indicate that it has been visited. Continue to search the neighboring nodes of the nodes in the queue iteratively until the queue is empty.

### Implementation

```cpp
class Solution {
    void sinkIsland(vector<vector<char>>& grid, int startI, int startJ) {
        deque<pair<int, int>> pairs;
        pairs.push_back(make_pair(startI, startJ));

        const auto tryAdd = [&grid, &pairs] (int i, int j) {
            if (i < 0 || j < 0) return;
            if (i >= grid.size() || j >= grid.front().size()) return;

            pairs.push_back({i, j});
        };

        while (!pairs.empty()) {
            const auto [i, j] = pairs.front();
            pairs.pop_front();

            if (grid[i][j] == '0') continue;
            grid[i][j] = '0';

            tryAdd(i - 1, j);
            tryAdd(i + 1, j);
            tryAdd(i, j - 1);
            tryAdd(i, j + 1);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.front().size(); ++j) {
                if (grid[i][j] == '1') {
                    ++nIslands;
                    sinkIsland(grid, i, j);
                }
            }
        }
        return nIslands;
    }
};
```

### Complexity Analysis

* Time Complexity: The time complexity is **O(M*N)**, where **M** represents the number of rows and **N** represents the number of columns.

* Space Complexity: The space complexity is **O(M*N)**.