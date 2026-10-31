class Solution:
    def numDecodings(self, s: str) -> int:
        prev, cur = 1, 1 if s[0] != "0" else 0
        for i in range(1, len(s)):
            nxt = 0
            if s[i] != "0":
                nxt += cur
            if s[i - 1] == "1" or (s[i - 1] == "2" and s[i] <= "6"):
                nxt += prev
            prev, cur = cur, nxt
        return cur
