#!/usr/bin/python3
""" Parsing the logs """

import sys

status_code = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

counts = {
    'size': 0,
    'lines': 1
}


def printv():
    """status code and size"""
    print('File size: {}'.format(counts['size']))
    for key in sorted(status_code.keys()):
        if status_code[key] > 0:
            print('{}: {}'.format(key, status_code[key]))


def read(line):
    """status and codes"""
    counts['size'] += int(line[-1])
    if line[-2] in status_code:
        status_code[line[-2]] += 1


if __name__ == '__main__':
    try:
        for line in sys.stdin:
            try:
                read(line.split(' '))
            except:
                pass
            if counts['lines'] % 10 == 0:
                printv()
            counts['lines'] += 1
    except KeyboardInterrupt:
        printv()
        raise
    printv()
