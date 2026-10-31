from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = []
        i = 0
        while i < len(words):
            j = i
            width = 0
            while j < len(words) and width + len(words[j]) + (j - i) <= maxWidth:
                width += len(words[j])
                j += 1
            gaps = j - i - 1
            if j == len(words) or gaps == 0:
                line = " ".join(words[i:j])
                lines.append(line + " " * (maxWidth - len(line)))
            else:
                spaces, extra = divmod(maxWidth - width, gaps)
                line = ""
                for k in range(i, j - 1):
                    line += words[k] + " " * (spaces + (1 if k - i < extra else 0))
                lines.append(line + words[j - 1])
            i = j
        return lines
