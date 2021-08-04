#!/usr/bin/python3
"""
0-main
"""


def pascal_triangle(n):
    """
    0-main
    """
    lst = [[0 for j in range(1, i + 2)] for i in range(n)]
    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if i == 0 or j == 0 or j == i:
                lst[i][j] = 1
            else:
                lst[i][j] = lst[i - 1][j] + lst[i - 1][j - 1]
    return lst
