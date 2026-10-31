from functools import lru_cache


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(maxsize=None)
        def scramble(a, b):
            if a == b:
                return True
            if sorted(a) != sorted(b):
                return False
            n = len(a)
            for i in range(1, n):
                if scramble(a[:i], b[:i]) and scramble(a[i:], b[i:]):
                    return True
                if scramble(a[:i], b[n - i:]) and scramble(a[i:], b[:n - i]):
                    return True
            return False

        return scramble(s1, s2)
