-- Name: Array_of_N_Elements
-- WWWW: https://www.hackerrank.com/challenges/fp-array-of-n-elements
-- Author: Jan Krepl

fn n = [1 .. n]

main = do
n <- readLn :: IO Int
print (fn(n))