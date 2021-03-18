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

    def checkColision(self, board, debug=False):
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
            if type(board.get(atx, aty)) is not str:
                return True
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
            if type(board.get(atx, aty)) is not str:
                return True
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
            if type(board.get(atx, aty)) is not str:
                return True
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
            if type(board.get(atx, aty)) is not str:
                return True
            atx -= 1
            aty += 1

        return False


class Board:

    def __init__(self, size):
        self.size = size
        self.matrix = [["." for x in range(size)] for y in range(size)]

    def placeQueen(self, Queen):
        self.matrix[Queen.y][Queen.x] = Queen

    def get(self, x, y):
        return self.matrix[y][x]

    def printBoard(self):
        for i in range(self.size):
            for j in range(self.size):
                if type(self.matrix[i][j]) is str:
                    print(" . ", end="")
                else:
                    print(" {} ".format(self.matrix[i][j].rep), end="")
            print()

    def getQueens(self):
        queens = []
        for i in range(self.size):
            for j in range(self.size):
                if type(self.matrix[j][i]) is not str:
                    queens.append([self.matrix[j][i].x, self.matrix[j][i].y])
        return queens

    def resetBoard(self):
        self.matrix = [["." for x in range(size)] for y in range(size)]


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
            board.placeQueen(Queen(j, i))
            for k in range(size):
                for c in range(size):
                    if not (k == i and c == j):
                        queen = Queen(c, k)
                        if not queen.checkColision(board):
                            board.placeQueen(queen)
            sol = board.getQueens()
            if len(sol) == size and sol not in solutions:
                solutions.append(sol)

    for i in solutions:
        print(i)
