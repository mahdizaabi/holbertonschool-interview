#!/usr/bin/python3
""" 0x10-rain """


def getWall(walls, startingIndex):
    """[summary]

    Args:
        walls ([type]): [description]
        startingIndex ([type]): [description]

    Returns:
        [type]: [description]
    """
    for value in walls[startingIndex:]:
        if value != 0:
            return value


def BorderLine(berg, index):
    """[summary]
    """
    if berg[index+1] == 0 and index+1 != len(berg) - 1:
        return True


def rain(walls):
    """[summary]

    Args:
        walls ([type]): [description]
    """

    if len(walls) == 0:
        return 0
    total = 0
    for index, value in enumerate(walls[:-1]):
        if value != 0 and BorderLine(walls, index):
            nextWallValue = getWall(walls, index)
            if value <= nextWallValue:
                total = total + value
            else:
                total = total + nextWallValue
    return total
