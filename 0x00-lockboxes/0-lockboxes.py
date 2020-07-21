#!/usr/bin/python3
def canUnlockAll(boxes):
    """check if all boxes can be opened"""
    keys = [i for i in boxes[0]]
    can_unlock = [False for i in boxes]
    can_unlock[0] = True
    for i in range(len(boxes)):
        if can_unlock[i] is False:
            if i in keys:
                can_unlock[i] = True
                keys += [k for k in boxes[i]]
                for j in boxes[i]:
                    keys += [k for k in boxes[j]]
            else:
                can_unlock[i] = False
    return all(can_unlock)
