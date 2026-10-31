class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        dp = [False] * (n + 1)
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    dp[j] = True
                else:
                    from_s1 = i > 0 and dp[j] and s1[i - 1] == s3[i + j - 1]
                    from_s2 = j > 0 and dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                    dp[j] = from_s1 or from_s2
        return dp[n]
