N, K = map(int, input().split())
num = [0] * 1001


def main():
    cnt = 0
    for i in range(2, N + 1):
        for j in range(i, N + 1, i):
            if num[j] == 0:
                num[j] = 1
                cnt += 1
                if cnt == K:
                    print(j)
                    return


main()


