class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        result = 1.0
        while n:
            if n & 1:
                result *= x
            x *= x
            n >>= 1
        return result
