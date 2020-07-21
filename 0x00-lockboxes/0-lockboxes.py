#!/usr/bin/python3
def canUnlockAll(boxes):
    """check if all boxes can be opened"""
    if type(boxes) is not list:
        return False
    if type(boxes[0]) is not list:
        return False
    if len(boxes[0]) == 0:
        return False
    keys = [i for i in boxes[0]]
    can_unlock = [False for i in boxes]
    can_unlock[0] = True
    try:
        for i in range(len(boxes)):
            if can_unlock[i] is False:
                if i in keys:
                    can_unlock[i] = True
                    for k in boxes[i]:
                        if k not in keys:
                            keys += [k]
                    for j in boxes[i]:
                        for k in boxes[j]:
                            if k not in keys:
                                keys += [k]
                else:
                    can_unlock[i] = False
    except:
        pass
    return all(can_unlock)
