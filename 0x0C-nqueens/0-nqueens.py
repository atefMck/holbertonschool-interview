#!/usr/bin/python3
"""brudda osas is da real brudda"""


import sys


class Queen:
    """brudda osas is da real brudda"""

    def __init__(self, x, y):
        """brudda osas is da real brudda"""
        self.x = x
        self.y = y
        self.rep = 'Q'

    def trimBoard(self, board, debug=False):
        """brudda osas is da real brudda"""
        atx = self.x + 1
        aty = self.y
        if debug:
            print("checking horizontal")
        while atx != self.x:
            if atx == board.size:
                atx = 0
            if atx == self.x:
                break
            if debug:
                print("Checking [{}, {}] = {}"
                      .format(atx, aty, board.get(atx, aty) == 'Q'))
            board.matrix[aty][atx] = 'x'
            atx += 1

        if debug:
            print("checking vertical")
        atx = self.x
        aty = self.y + 1
        while aty != self.y:
            if aty == board.size:
                aty = 0
            if aty == self.y:
                break
            if debug:
                print("Checking [{}, {}] = {}".format(
                    atx, aty, board.get(atx, aty) == 'Q'))
            board.matrix[aty][atx] = 'x'
            aty += 1

        if debug:
            print("checking first diagonal")
        atx = self.x + 1
        aty = self.y + 1
        while atx != self.x and aty != self.y:
            if atx == board.size:
                atx = atx - aty
                aty = 0
            if aty == board.size:
                aty = aty - atx
                atx = 0
            if atx == self.x and aty == self.y:
                break
            if debug:
                print("Checking [{}, {}] = {}".format(
                    atx, aty, board.get(atx, aty) == 'Q'))
            board.matrix[aty][atx] = 'x'
            atx += 1
            aty += 1

        if debug:
            print("checking second diagonal")
        atx = self.x - 1
        aty = self.y + 1
        while atx != self.x and aty != self.y:
            if atx == -1:
                aux = atx + 1
                atx = aty - 1
                aty = aux
            if aty == board.size:
                aux = atx + 1
                atx = aty - 1
                aty = aux
            if atx == self.x and aty == self.y:
                break
            if debug:
                print("Checking [{}, {}] = {}".format(
                    atx, aty, board.get(atx, aty) == 'Q'))
            board.matrix[aty][atx] = 'x'
            atx -= 1
            aty += 1


class Board:

    def __init__(self, size):
        self.size = size
        self.matrix = [["." for x in range(size)] for y in range(size)]

    def placeQueen(self, Queen):
        self.matrix[Queen.y][Queen.x] = 'Q'

    def get(self, x, y):
        return self.matrix[y][x]

    def printBoard(self):
        for i in range(self.size):
            for j in range(self.size):
                print(" {} ".format(self.matrix[i][j]), end="")
            print()

    def getQueens(self):
        queens = []
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[j][i] == 'Q':
                    queens.append([i, j])
        return queens

    def resetBoard(self):
        self.matrix = [["." for x in range(size)] for y in range(size)]

    def solveNQueens(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[j][i] != 'x':
                    queen = Queen(i, j)
                    queen.trimBoard(self)
                    self.placeQueen(queen)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        size = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        sys.exit(1)
    if size < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = Board(size)
    solutions = []
    for i in range(size):
        for j in range(size):
            board.resetBoard()
            queen = Queen(i, j)
            queen.trimBoard(board)
            board.placeQueen(queen)
            board.solveNQueens()
            if len(board.getQueens()) == size:
                if board.getQueens() not in solutions:
                    solutions.append(board.getQueens())

    for i in solutions:
        print(i)
