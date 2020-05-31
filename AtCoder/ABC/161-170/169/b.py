import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N, *A = map(int, read().split())

ans=1
zero=False
for a in A:
    if a==0:
        zero=True
        break

if zero:
    print(0)
else:
    over=False
    for a in A:
        ans*=a
        if ans>1e18:
            print(-1)
            over=True
            break
    if not over:
        print(ans)
