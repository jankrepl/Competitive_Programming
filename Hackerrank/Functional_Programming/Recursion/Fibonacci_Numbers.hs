-- Name: Fibonacci_Numbers
-- WWWW: https://www.hackerrank.com/challenges/functional-programming-warmups-in-recursion---fibonacci-numbers
-- Author: Jan Krepl

--Contributed by Ron Watkins
module Main where

fib 0 = 1
fib 1 = 0
fib n = fib (n-2) + fib (n-1)


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
    input <- getLine
    print . fib . (read :: String -> Int) $ input
