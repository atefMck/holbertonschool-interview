#!/usr/bin/python3
"""
Minimum operations module
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result n characters
    """
    op_count = 0
    while n != 1:
        if n % 2 == 1:
            n = n - 1
            op_count = op_count + 1
        else:
            n = n // 2
            op_count = op_count + 2
        if n < 1:
            return 0
    return op_count
