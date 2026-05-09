class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        last_visited = {}
        left = 0

        for right, char in enumerate(s):
            if char in last_visited:
                left = max(last_visited[char], left)
            max_length = max(max_length, right - left + 1)
            last_visited[char] = right + 1

        return max_length
