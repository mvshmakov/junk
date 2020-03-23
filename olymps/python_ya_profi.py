from sys import stdin
from hashlib import md5
from math import factorial, ceil

def mean(nums):
    return sum(nums, 0.0) / len(nums)

for line in stdin:
    line_list = list(line)
    first_symbol = line_list[0]

    new_last_symbol = ''

    if line_list[0].isalpha():
        next_ascii_symbol = chr(ord(first_symbol) + 1)

        if (next_ascii_symbol.isalpha()):
            if (next_ascii_symbol.islower()):
                next_ascii_symbol.upper()
            else:
                next_ascii_symbol.lower()

        new_last_symbol = next_ascii_symbol
    else:
        calculated_next_symbol = factorial(first_symbol) + ord(first_symbol)
        new_last_symbol = calculated_next_symbol

    line_list.append(new_last_symbol)

    digit_list = [x for x in input() if x.isdigit()]
    if (len(digit_list) == 0):
        line_list.append(ord('$'))
    else:
        line_list.append(
            str(ceil(mean(digit_list)))
        )

    print(
        md5(''.join(line_list).encode('utf-8')).hexdigest()
    )
