#!/usr/bin/python3
'''
    a script that reads stdin line by line and computes metrics
'''


import sys


def addFileSize(data):
    return int(data.split()[8])


def codes(data):
    return data.split()[7]

i = 0
s = 0
stat = ['200', '301', '400', '401', '403', '404', '405', '500']
new = [0, 0, 0, 0, 0, 0, 0, 0]

try:
    for line in sys.stdin:
        c = line.split()
        if len(c) > 2:
            if c[-2] in stat:
                x = stat.index(c[-2])
                new[x] = new[x] + 1
            i += 1
            s = s + int(c[-1])
        if i == 10:
            i = 0
            print("File size: {}".format(s))
            for x in range(8):
                if new[x] != 0:
                    print('{}: {}'.format(stat[x], new[x]))
except Exception:
    pass
finally:
    print("File size: {}".format(s))
    for x in range(8):
        if new[x] != 0:
            print("{}: {}".format(stat[x], new[x]))
