class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        digits = [str(d) for d in range(1, n + 1)]
        factorial = [1] * (n + 1)
        for i in range(1, n + 1):
            factorial[i] = factorial[i - 1] * i
        k -= 1
        result = []
        for remaining in range(n, 0, -1):
            index, k = divmod(k, factorial[remaining - 1])
            result.append(digits.pop(index))
        return "".join(result)
