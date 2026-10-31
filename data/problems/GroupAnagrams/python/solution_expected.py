from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for word in strs:
            groups.setdefault("".join(sorted(word)), []).append(word)
        return sorted(sorted(group) for group in groups.values())
