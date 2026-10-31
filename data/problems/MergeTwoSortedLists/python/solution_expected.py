from typing import List


class Solution:
    def mergeTwoLists(self, list1: List[int], list2: List[int]) -> List[int]:
        merged = []
        i = j = 0
        while i < len(list1) and j < len(list2):
            if list1[i] <= list2[j]:
                merged.append(list1[i])
                i += 1
            else:
                merged.append(list2[j])
                j += 1
        return merged + list1[i:] + list2[j:]
