#!/usr/bin/python
""" minimum operation """


def minOperations(n):
    """ check the minimum number of operation """


    if n < 2:
        return 0
    res = 0
    i = 2
    while i <= n:
        while n % i == 0:
            res = res + i
            n = n/i
        i = i + 1
    return(res)
