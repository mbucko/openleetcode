
class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        best_len = 1

        def expand(left: int, right: int) -> None:
            nonlocal start, best_len
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            length = right - left - 1
            if length > best_len:
                best_len = length
                start = left + 1

        for center in range(len(s)):
            expand(center, center)
            expand(center, center + 1)

        return s[start:start + best_len]
