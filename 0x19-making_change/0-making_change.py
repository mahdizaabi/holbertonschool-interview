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
coinsNumber = 0
    if total <= 0:
        return 0
    coins.sort()
    coins.reverse()
    for coin in coins:
        coinsNumber += total // c
        total = total % coin
    if (total != 0):
        return -1
    return coinsNumber
