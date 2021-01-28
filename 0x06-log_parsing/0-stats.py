#!/usr/bin/python3
'''log parsing'''


import sys
import re

data_Buffer = []
somme = 0

status = {
    "200": [],
    "301": [],
    "400": [],
    "401": [],
    "403": [],
    "404": [],
    "405": [],
    "500": []}
counter = 0
regex = '([(\d\.)]+) - \[(.*?)\] "(.*?)" (\d+) (\d+)'

try:
    for line in sys.stdin:
        if counter == 9:
            for i in data_Buffer:
                somme = somme + int(i)
            print('File size: {}'.format(somme))
            for key, value in status.items():
                print('{}: {}'.format(key, len(value)))
            status = {
               "200": [],
               "301": [],
               "400": [],
               "401": [],
               "403": [],
               "404": [],
               "405": [],
               "500": []}
            counter = 0
            somme = 0
            data_Buffer = []

        if re.match(regex, line).groups()[3] in status.keys():
            status[re.match(regex, line).groups()[3]].append(1)
            data_Buffer.append(re.match(regex, line).groups()[4])
            counter = counter + 1
            continue
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(somme))
    for key, value in status.items():
                print('{}: {}'.format(key, len(value)))

