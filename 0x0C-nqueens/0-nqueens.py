#!/usr/bin/python3
"""
program that solves the N queens problem :
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard.
"""

from sys import argv


def isOk(tab, r, z):
    """
    isOk
    """
    try:
        for y in range(r):
            if tab[y] == z or tab[y] + r - y == z or tab[y] + y - r == z:
                return False
        return True
    except:
        pass


def fix(tab, r):
    """
    fix
    """
    try:
        for y in range(len(tab)):
            if isOk(tab, r, y):
                tab[r] = y
                if r < len(tab) - 1:
                    fix(tab, r + 1)
                else:
                    print([[y, tab[y]] for y in range(len(tab))])
    except:
        pass

try:
    if len(argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
        a = int(argv[1])
        print("N must be a number")
        sys.exit(1)
        if a < 4:
            print("N must be at least 4")
            sys.exit(1)
except:
    pass
a = int(argv[1])
tab = [-1 for b in range(a)]
fix(tab, 0)
