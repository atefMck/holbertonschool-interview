#!/usr/bin/python3
def canUnlockAll(boxes):
    """check if all boxes can be opened"""
    keys = [0] + [i for i in boxes[0]]
    needed_keys = [i for i in range(len(boxes))]
    for j in keys:
        if j < len(boxes):
            for k in boxes[j]:
                print(k)
                if k not in keys:
                    keys.append(k)
    for k in needed_keys:
        if k not in keys:
            return False
    return True
