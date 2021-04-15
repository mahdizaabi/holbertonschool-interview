#!/usr/bin/python3
""" 0x10-rain """


def rain(walls):
    """[summary]

    Args:
        walls ([type]): [description]
        n ([type]): [description]

    Returns:
        [type]: [description]
    """

    if len(walls) == 0:
        return 0
    res = 0
    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        res = res + (min(left, right) - walls[i])

    return res
