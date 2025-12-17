from typing import List

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)
        if n == 0 or k == 0:
            return 0
        
        # dp[t][state]
        # state: 0 = no stock, 1 = holding buy, 2 = holding short
        dp = [[float('-inf')] * 3 for _ in range(k + 1)]
        dp[0][0] = 0
        
        for price in prices:
            for t in range(k, -1, -1):
                # Do nothing
                dp[t][0] = max(dp[t][0], dp[t][0])
                
                # Buy
                if t > 0:
                    dp[t][1] = max(dp[t][1], dp[t - 1][0] - price)
                
                # Sell buy-position
                dp[t][0] = max(dp[t][0], dp[t][1] + price)
                
                # Short sell
                if t > 0:
                    dp[t][2] = max(dp[t][2], dp[t - 1][0] + price)
                
                # Buy back short-position
                dp[t][0] = max(dp[t][0], dp[t][2] - price)
        
        return max(dp[t][0] for t in range(k + 1))
