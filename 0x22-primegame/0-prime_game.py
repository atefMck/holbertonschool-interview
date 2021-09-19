#!/usr/bin/python3
'''
Woooooooooo
'''


def isPrime(num):
    '''
    Woooooooooo
    '''
    if num > 1:
        for i in range(2, int(num/2)+1):
            if (num % i) == 0:
                return False
        return True
    else:
        return False


def isWinner(x, nums):
    '''
    Woooooooooo
    '''
    roundsWon = {
        "Maria": 0,
        "Ben": 0
    }
    turn = 0
    for i in range(x):
        choices = [i for i in range(1, nums[i] + 1)]
        for j in choices:
            if (isPrime(j)):
                for k in choices:
                    if k % j == 0:
                        choices.remove(k)
                    turn = turn + 1 % 2
        if turn == 0:
            roundsWon["Maria"] += 1
            turn = 1
        else:
            roundsWon["Ben"] += 1
            turn = 0

    if roundsWon["Maria"] > roundsWon["Ben"]:
        return "Maria"
    elif roundsWon["Maria"] < roundsWon["Ben"]:
        return "Ben"
    else:
        return None
