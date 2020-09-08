from math import floor, ceil, sqrt

# n번째 중심수의 번호
def get_idx_mommy(n):
    return 2 * (n ** 2) - n + 1

def get_idx_son(n):
    return 2 * (n ** 2) - 3 * n + 2

# x 번째 수가 속한 구간
def get_term_mommy(x):
    return (1 + sqrt(8 * x - 7))/4

def get_term_son(x):
    return (3 + sqrt(8 * x - 7))/4


def get_num(x, center, center_idx, left):
    return center - (center_idx - x) * left


# x 번째 수 구하기
def get_xth_num(x, get_term, get_idx, is_son):
    term = get_term(x)
    center1, center2 = floor(term), ceil(term)
    if center1 == center2:
        return center1 * 2 - is_son

    center1_idx = get_idx(center1)
    center2_idx = get_idx(center2)

    center1 = center1 * 2 - is_son
    if x < center1_idx + center1:
        return get_num(x, center1, center1_idx, -1)
    else:
        return get_num(x, center2 * 2 - is_son, center2_idx, 1)

def get_mommy(x):
    return get_xth_num(x, get_term_mommy, get_idx_mommy, False)

def get_son(x):
    return get_xth_num(x, get_term_son, get_idx_son, True)


x = int(input())
print(str(get_son(x)) + "/" + str(get_mommy(x)))