from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        parts = []

        def build(start):
            if len(parts) == 4:
                if start == len(s):
                    result.append(".".join(parts))
                return
            for length in range(1, 4):
                piece = s[start:start + length]
                if len(piece) < length:
                    break
                if (piece[0] == "0" and length > 1) or int(piece) > 255:
                    break
                parts.append(piece)
                build(start + length)
                parts.pop()

        build(0)
        return sorted(result)
