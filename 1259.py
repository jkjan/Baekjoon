def isPalindrome(num)->str:
    start = 0
    end = len(num)-1
    while start < end:
        if num[start] != num[end]:
            return "no"
        start += 1
        end -= 1
    return "yes"


while True:
    num = input()
    if num == '0':
        break
    print(isPalindrome(num))

