#!/usr/bin/python3
""" Check if cratess can be opened """


def canUnlockAll(boxes):
    """ Checks if box can be opened """
    unlocked = [False] * len(boxes)
    unlocked[0] = True
    keys_dic = []

    for key in boxes[0]:
        keys_dic.append(key)

    for key in keys_dic:
        if ((key < len(boxes)) and (unlocked[key] is False)):
            unlocked[key] = True
            for row in boxes[key]:
                if row not in keys:
                    keys_dic.append(row)

    if False in unlocked:
        return False
    else:
        return True
