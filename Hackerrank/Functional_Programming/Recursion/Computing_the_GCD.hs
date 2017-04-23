-- Name: Computing_the_GCD
-- WWWW: https://www.hackerrank.com/challenges/functional-programming-warmups-in-recursion---gcd
-- Author: Jan Krepl

module Main where


gcd' :: Integral a => a -> a -> a
-- gcd' n m = gcd n m -- simple
gcd' n m = do
    if n == m
        then n
        else if n > m 
            then gcd' (n-m) m
            else gcd' m n


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)
