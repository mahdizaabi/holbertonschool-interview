#!/usr/bin/python3
""" 0x10-rain """


def getWall(walls, startingIndex):
    """[function that calculate how much water
    will be retained after it rains]

    Args:
        walls ([type]): [description]
        startingIndex ([type]): [description]

    Returns:
        [type]: [description]
    """
    for value in walls[startingIndex+1:]:
        if value != 0:
            return value


def pop_zeros(items):
    """[function that calculate how much water
    will be retained after it rains]

    Args:
        items ([type]): [description]
    """
    while items[-1] == 0:
        items.pop()


def BorderLine(berg, index):
    """[function that calculate how much water
    will be retained after it rains]
    """
    if berg[index+1] == 0:
        return True


def rain(walls):
    """[function that calculate how much water
    will be retained after it rains]

    Args:
        walls ([type]): [description]
    """

    if len(walls) == 0:
        return 0
    total = 0
    t = 0
    for ele in range(0, len(walls)):
        t = t + walls[ele]

    if t == 0:
        return 0
    pop_zeros(walls)
    for index, value in enumerate(walls[:-1]):
        if value != 0 and BorderLine(walls, index):
            nextWallValue = getWall(walls, index)
            if value <= nextWallValue:
                total = total + value
            else:
                total = total + nextWallValue
    return total
