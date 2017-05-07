# Name: Fibonacci_Modified
# WWWW: https://www.hackerrank.com/challenges/fibonacci-modified
# Author: Jan Krepl


t1, t2, n = map(int,input().split())

l = [t1, t2]

index = 2

while index < n:
    temp = l[-1] * l[-1] + l[-2]
    l.append(temp)
    index += 1

print(l[-1])

