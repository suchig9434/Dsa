from typing import List

class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)

        # Base profit
        base_profit = 0
        for i in range(n):
            if strategy[i] == 1:
                base_profit += prices[i]
            elif strategy[i] == -1:
                base_profit -= prices[i]

        # Prefix sums for prices
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + prices[i]

        # Prefix contribution of original strategy
        contrib = [0] * (n + 1)
        for i in range(n):
            contrib[i + 1] = contrib[i]
            if strategy[i] == 1:
                contrib[i + 1] += prices[i]
            elif strategy[i] == -1:
                contrib[i + 1] -= prices[i]

        best = base_profit
        half = k // 2

        for start in range(n - k + 1):
            end = start + k

            # Remove original contribution in window
            removed = contrib[end] - contrib[start]

            # Add modified contribution:
            # first half -> hold (0)
            # second half -> sell (1)
            added = prefix[end] - prefix[start + half]

            new_profit = base_profit - removed + added
            best = max(best, new_profit)

        return best
