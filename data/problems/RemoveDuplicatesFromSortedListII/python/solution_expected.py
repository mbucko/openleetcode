from typing import List


class Solution:
    def deleteDuplicates(self, head: List[int]) -> List[int]:
        result = []
        i = 0
        while i < len(head):
            j = i
            while j < len(head) and head[j] == head[i]:
                j += 1
            if j - i == 1:
                result.append(head[i])
            i = j
        return result
