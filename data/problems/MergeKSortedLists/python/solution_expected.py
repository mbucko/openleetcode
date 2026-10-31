from typing import List
import heapq


class Solution:
    def mergeKLists(self, lists: List[List[int]]) -> List[int]:
        heap = [(lst[0], i, 0) for i, lst in enumerate(lists) if lst]
        heapq.heapify(heap)
        merged = []
        while heap:
            value, i, j = heapq.heappop(heap)
            merged.append(value)
            if j + 1 < len(lists[i]):
                heapq.heappush(heap, (lists[i][j + 1], i, j + 1))
        return merged
