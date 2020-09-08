from collections import OrderedDict
import sys

N = int(input())

members = []

for i in range(N):
    member = sys.stdin.readline().split()
    age = int(member[0])
    name = member[1]
    members.append((age, name))

sorted_member = sorted(members, key=lambda x:x[0])

for m in sorted_member:
    sys.stdout.write("%d %s\n" % (m[0], m[1]))