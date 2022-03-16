#!/usr/bin/python3
"""
returns a list of lists of integers representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """ pascal triangle
"""
    triangle = []
    for i in range(n):
        actualNumber = [None for _ in range(i + 1)]
        actualNumber[0], actualNumber[-1] = 1, 1
        for j in range(1, len(actualNumber) - 1):
            actualNumber[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
        triangle.append(actualNumber)
    return triangle
