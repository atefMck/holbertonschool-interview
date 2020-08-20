#!/usr/bin/python3
"""
Minimum operations module
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result n characters
    """
    op_count = 0
    i = 2
    while n > 1:
        while n % i == 0:
            op_count += i
            n = n // i
        i += 1
    return op_count
