#!/usr/bin/python3
"""
Minimum operations module
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result n characters
    """
    op_count = 0
    for i in range(2, n):
        while n % i == 0:
            op_count += i
            n = n // i
    return op_count
