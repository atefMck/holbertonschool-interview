#!/usr/bin/python3
"""
    Computes stdin input
"""

import sys


def parse_data(data):
    data = data.replace(' "GET /projects/260 HTTP/1.1"',
                        "").replace(' -', "").replace('[', "").replace(']', "")
    if data.count("-") == 3:
        data = data.replace('-', " ", 1)
    array = data.split()
    if len(array) != 5:
        return
    return array


i = 0
size = 0
status_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
try:
    for line in sys.stdin:
        i += 1
        array = parse_data(line)
        if array:
            size += int(array[4])
            if array[3] in status_code.keys():
                status_code[array[3]] += 1
        if i == 10:
            print("File size: {}".format(size))
            for k in sorted(status_code):
                if status_code[k] != 0:
                    print("{}: {}".format(k, status_code[k]))
            i = 0
except Exception:
    pass
finally:
    print("File size: {}".format(size))
    for k in sorted(status_code):
        if status_code[k] != 0:
            print("{}: {}".format(k, status_code[k]))
    i = 0