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
    if len(coins) == 0 or total <= 0:
        return -1
    coinsNumber = 0
    for i in range(len(coins)):
        for j in range(len(coins) - 1):
            if coins[j] < coins[j+1]:
                temp = coins[j+1]
                coins[j+1] = coins[j]
                coins[j] = temp
    for coin in coins:
        coinsNumber += total // coin
        total = total % coin
    if (total != 0):
        return -1
    return coinsNumber
