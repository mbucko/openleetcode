class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # Knuth-Morris-Pratt: fail[i] is the length of the longest proper
        # prefix of needle[:i + 1] that is also its suffix.
        fail = [0] * len(needle)
        length = 0
        for i in range(1, len(needle)):
            while length and needle[i] != needle[length]:
                length = fail[length - 1]
            if needle[i] == needle[length]:
                length += 1
            fail[i] = length
        matched = 0
        for i, ch in enumerate(haystack):
            while matched and ch != needle[matched]:
                matched = fail[matched - 1]
            if ch == needle[matched]:
                matched += 1
            if matched == len(needle):
                return i - len(needle) + 1
        return -1
