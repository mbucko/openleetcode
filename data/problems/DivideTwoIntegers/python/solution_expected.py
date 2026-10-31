class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        if dividend == -2**31 and divisor == -1:
            return INT_MAX
        negative = (dividend < 0) != (divisor < 0)
        a, b = abs(dividend), abs(divisor)
        quotient = 0
        for shift in range(31, -1, -1):
            if (a >> shift) >= b:
                a -= b << shift
                quotient += 1 << shift
        return -quotient if negative else quotient
