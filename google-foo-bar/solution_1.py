# "The cake is not a lie!" challenge

test_string = "abccbaabccba"


def solution(s):
    s_len = len(s)
    for pattern_len in range(1, s_len + 1):
        pattern = s[:pattern_len]
        pattern_count = s.count(pattern)

        if pattern_count * pattern_len == s_len:
            return pattern_count


if __name__ == "__main__":
    print(solution(test_string))
