#!/usr/bin/python3
"""minimum operation"""


def minOperations(n):
    """check for minimum operations"""

    if n == 1:
        return 0
    if n == 2:
        return 2
    for i in range(3, 10):
        if n % i == 0:
            return int(n/i + i)
    return 0

