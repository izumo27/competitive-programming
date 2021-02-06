from decimal import Decimal
import math

x, y, r=map(Decimal, input().split())

start=math.ceil(x-r)
end=math.floor(x+r)

num=0

for i in range(start, end+1):
  p=(r*r-(x-i)*(x-i)).sqrt()
  a=math.ceil(y-p)
  b=math.floor(y+p)
  num+=b-a+1
print(num)
