class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        len_s, len_p = len(s), len(p)
        dp = [[False] * (len_p + 1) for _ in range(len_s + 1)]
        dp[0][0] = True 
        
        for j in range(1, len_p + 1):
            if p[j-1] == '*' and j >= 2:
                dp[0][j] = dp[0][j-2]
        
        for i in range(1, len_s + 1):
            for j in range(1, len_p + 1):
                if p[j-1] == '*':
                    if j >= 2:
                        dp[i][j] = dp[i][j-2]
                    if j >= 2 and (p[j-2] == s[i-1] or p[j-2] == '.'):
                        dp[i][j] |= dp[i-1][j]
                else:
                    if p[j-1] == '.' or p[j-1] == s[i-1]:
                        dp[i][j] = dp[i-1][j-1]
        
        return dp[len_s][len_p]

        
