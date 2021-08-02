#!/usr/bin/python3

def makeChange(coins, total):
    rest = total
    num_coins = 0
    while rest != 0:
        max_coin = max(coins)
        num = rest // max_coin
        rest = rest - (max_coin * num)
        num_coins += num
        coins.pop(coins.index(max_coin))
        if len(coins) == 0 and rest > 0:
            return -1
    return num_coins
