#!/usr/bin/python3
"""backtrack n_queens"""
import sys


def check_queen(p):
    """checks for position availability"""
    for i in range(len(p) - 1):
        d = p[i] - p[len(p) - 1]
        if d == 0 or d * (-1) == len(p) - 1 - i or d == len(p) - 1 - i:
            return False
    return True


def n_queen(N, r, sol, p):
    """appends to and pops from solution"""
    if r == N:
        print(sol)
    else:
        for i in range(N):
            p.append(i)
            sol.append([r, i])
            if check_queen(p):
                n_queen(N, r + 1, sol, p)
            p.pop()
            sol.pop()


if len(sys.argv) < 2:
    print("Usage: nqueens N")
    sys.exit(1)
n = int(sys.argv[1])
if type(n) != int:
    print("N must be a number")
    sys.exit(1)
if n < 4:
    print("N must be at least 4")
    sys.exit(1)
solution = []
pos = []
row = 0
n_queen(n, row, solution, pos)
