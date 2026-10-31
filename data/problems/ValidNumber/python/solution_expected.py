class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = seen_dot = seen_exp = False
        for i, ch in enumerate(s):
            if ch.isdigit():
                seen_digit = True
            elif ch in "+-":
                if i > 0 and s[i - 1] not in "eE":
                    return False
            elif ch in "eE":
                if seen_exp or not seen_digit:
                    return False
                seen_exp = True
                seen_digit = False
            elif ch == ".":
                if seen_dot or seen_exp:
                    return False
                seen_dot = True
            else:
                return False
        return seen_digit
