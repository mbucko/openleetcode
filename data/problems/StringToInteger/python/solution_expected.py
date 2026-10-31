class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        i = 0
        while i < len(s) and s[i] == " ":
            i += 1
        sign = 1
        if i < len(s) and s[i] in "+-":
            sign = -1 if s[i] == "-" else 1
            i += 1
        result = 0
        while i < len(s) and s[i].isdigit():
            result = result * 10 + int(s[i])
            i += 1
        return max(INT_MIN, min(INT_MAX, sign * result))
