#!/usr/bin/python3
'''
script that reads stdin line by line and computes metrics:
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
<status code> <file size>
'''
import sys

total_size = {'size': 0}
codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}


def resume():
    '''
    print statistics
    '''
    print('File size: {}'.format(total_size['size']))
    for key in sorted(codes.keys()):
        if codes[key] > 0:
            print('{}: {}'.format(key, codes[key]))


def calc_metrics(line):
    '''
        Operates with the resume stats
    '''
    try:
        line = line.split(' ')
        size = line[-1]
        total_size['size'] += int(size)
        if line[-2] in codes:
            codes[line[-2]] += 1
    except Exception:
        pass


if __name__ == '__main__':
    num_lines = 1
    try:
        for line in sys.stdin:
            calc_metrics(line)
            if num_lines % 10 == 0:
                resume()
            num_lines += 1
    except KeyboardInterrupt:
        resume()
        raise
    resume()
