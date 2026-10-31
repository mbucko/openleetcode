### Approach

Split the path on '/' and keep a stack of directory names. Skip empty parts (from repeated slashes) and ".". ".." pops the stack if it isn't empty. Any other part is pushed. Join the stack with single slashes after a leading '/'.

### Implementation

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        for part in path.split("/"):
            if part == "..":
                if stack:
                    stack.pop()
            elif part and part != ".":
                stack.append(part)
        return "/" + "/".join(stack)
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
