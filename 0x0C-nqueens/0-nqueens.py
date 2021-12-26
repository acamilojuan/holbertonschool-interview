#!/usr/bin/python3
"""Nqueens"""

import sys


def checkQueen(queens, queen):
    """Check array queen"""
    for x, y in queens:
        if y == queen[1]:
            return False
        if abs((y - queen[1]) / (x - queen[0])) == 1:
            return False
    return True


def placeQueen(n, queens, solutions):
    """localizate place of queen"""
    if len(queens) == n:
        for q in queens:
            solutions.append(q)
        return

    for y in range(n):
        queen = [len(queens), y]
        if checkQueen(queens, queen):
            queens.append(queen)
            placeQueen(n, queens, solutions)
            queens.pop()


def main():
    """main"""
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)

    if not sys.argv[1].isnumeric():
        print('N must be a number')
        sys.exit(1)

    number = int(sys.argv[1])

    if number < 4:
        print('N must be at least 4')
        sys.exit(1)

    solutions = []
    placeQueen(number, [], solutions)

    tmp = []

    count = 0
    for m in solutions:
        count += 1
        tmp.append(m)
        if count == number:
            count = 0
            print(tmp)
            tmp = []


if __name__ == '__main__':
    main()
