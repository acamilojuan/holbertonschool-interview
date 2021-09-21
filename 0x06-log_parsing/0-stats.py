#!/usr/bin/python3
""" Reading and computing """

if __name__ == '__main__':

    import sys
    import collections

    count = 0
    size = 0
    status = {'200': 0, '301': 0, '400': 0, '401': 0,
              '403': 0, '404': 0, '405': 0, '500': 0}

    try:
        for line in sys.stdin:
            count += 1
            parse = line.split()

            try:
                size += int(parse[-1])

                for keys in status.keys():
                    if keys == parse[-2]:
                        status[keys] += 1
            except:
                pass

            if count == 10:
                print('File size: {}'.format(size))
                od = collections.OrderedDict(sorted(status.items()))
                for keys, values in od.items():
                    if values != 0:
                        print('{}: {}'.format(keys, values))
                count = 0

    except KeyboardInterrupt:
        print('File size: {}'.format(size))
        od = collections.OrderedDict(sorted(status.items()))
        for keys, values in od.items():
            if values != 0:
                print('{}: {}'.format(keys, values))
        raise

    print('File size: {}'.format(size))
    od = collections.OrderedDict(sorted(status.items()))
    for keys, values in od.items():
        if values != 0:
                print('{}: {}'.format(keys, values))
