from typing import List


class Solution:
    def addTwoNumbers(self, l1: List[int], l2: List[int]) -> List[int]:
        result = []
        carry = 0
        i = 0
        while i < len(l1) or i < len(l2) or carry:
            total = carry
            if i < len(l1):
                total += l1[i]
            if i < len(l2):
                total += l2[i]
            result.append(total % 10)
            carry = total // 10
            i += 1
        return result
