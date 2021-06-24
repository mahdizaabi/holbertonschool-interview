#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """[summary]

    Args:
        coins ([type]): [description]
        total ([type]): [description]

    Returns:
        [type]: [description]
    """
    if len(coins) == 0 or total == 0:
        return -1
    coin = 0
    neededCoins = 0
    remainingCoins = total
    flag = False
    for i in range(len(coins)):
        if coin != 0:
            neededCoins = remainingCoins // coin + neededCoins
            remainingCoins = remainingCoins % coin
            if remainingCoins == 0:
                flag = True
                break
        for j in range(len(coins) - 1):
            if coins[j] > coins[j+1]:
                temp = coins[j+1]
                coins[j+1] = coins[j]
                coins[j] = temp
        coin = coins[len(coins) - i - 1]
    if(flag):
        return neededCoins
    else:
        return -1
