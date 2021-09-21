#!/usr/bin/python3
"""
Checking if a data set is valid UTF-8 encoded
"""


def validUTF8(data):
    """
    Checking if a data set is valid UTF-8 encoded
    """
    count = 0
    for row in data:
        res = format(row, '#010b')[-8:]
        if count == 0:
            for bit in res:
                if bit == '0':
                    break
                count += 1
            if count == 0:
                continue
            if count == 1 or count > 4:
                return False
        else:
            if not (res[0] == '1' and res[1] == '0'):
                return False
        count = count - 1
    if not count:
        return True
    else:
        return False
