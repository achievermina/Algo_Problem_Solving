def maxProfit(self, prices: List[int]) -> int:

    max_profit=0
    min_price = float('inf')

    for price in prices:
        min_price = min(price, min_price)
        max_profit = max(max_profit, price-min_price)
        return max_profit





    ### RUNNING BUT TIME LIMIT EXCEEDED

    # max = 0
    # # i is buying j is selling
    #
    # for i in range(len(prices)):
    #     for j in range(i + 1, len(prices)):
    #         if (prices[j] - prices[i]) > max and j > i:
    #             max = (prices[j] - prices[i])
    #
    # return max


if __name__ == '__main__':
    listPrice = [2,4,8]
    maxProfit(listPrice)
