# "Bunny Prisoner Locating" challenge

# | 16
# | 11 17
# | 7 12 18
# | 4 8 13 19
# | 2 5 9 14 20
# | 1 3 6 10 15 21


def solution(x, y):
    n = x + y - 1
    x_diag_row = n * (n + 1) // 2

    return str(x_diag_row - y + 1)


if __name__ == "__main__":
    print(solution(6, 1))
