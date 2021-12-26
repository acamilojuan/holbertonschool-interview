#!/usr/bin/python3
''' Module to solve the N Queens Problem '''

import sys
global N
N = sys.argv[1]

def printSolution(board):
    for i in range(N):
        for j in range(N):
            print(board[i][j])
            
def nqueens(nQ):
    grid = []
    try:
        for i in range(nQ - 1):
            grid[i].add("*")
            for j in range(nQ - 1):
                grid[i][j].add("#")
    except IndexError:
        print("Usage: nqueens N")
        exit(1)

    print(grid)
    return(grid)
    
def test_answer():
    assert nqueens("i") == "N must be a number"

if __name__ == "__main__":
    storeGrid = []
    try:
        args = len(sys.argv)
        n = int(sys.argv[1])
        
        if(args == 0 | args > 2):
            print("Usage: nqueens N")
            exit(1)
        
        if(n < 4):
            print("N must be at least 4")
            exit(1)
        
        storeGrid = nqueens(n)
        for spots in storeGrid:
            print(spots)

    except ValueError:
        '''When arg not a number'''
        print("N must be a number")
        exit(1)
