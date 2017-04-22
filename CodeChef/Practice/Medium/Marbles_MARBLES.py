# Name: Marbles
# Problem_Code: MARBLES
# WWW: https://www.codechef.com/problems/MARBLES
# Author: Jan Krepl

import numpy as np 
import operator as op
from functools import *

# Why in Python? I am not sure whether numerators or denomintors wont overflow (even after cancelling out). We 
# are only guaranteed that the result = ratio is a 64 bit...but thats not enough..not

# define efficient  "n choose r"
# 2 hacks: 1) Avoid recursion - rather use grid multiplication
#          2) cancel out the fraction before numer and denom
def ncr(n, r):
    r = min(r, n-r) # n chose r == n chose (n-r) 
    if r == 0: return 1
    # we want to avoid computing 
    numer = reduce(op.mul, range(n, n-r, -1)) # [n, n-1, n-2, .... , n-r + 1]
    denom = reduce(op.mul, range(1, r+1)) # [1, 2, 3, 4, ..., r ]
    return numer//denom

T = int(input())
for _ in range(T):
    n, k = map(int, input().split()) 
    # so we have k colours to choose from to create n-sized sets -- combinations with repetition
    # however, Rohit wants to have each color at least ones...so that restrings the degrees of freedom
    # N = k ... number of different types (colours)
    # r = N-k .. number of instances we want to select from the types ... k of them are already deternined 
    N = k
    r = n - k
    print(ncr(N + r - 1,r))