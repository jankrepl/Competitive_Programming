-- Name: List_Replication
-- WWWW: https://www.hackerrank.com/challenges/fp-list-replication
-- Author: Jan Krepl

f :: Int -> [Int] -> [Int]
f n arr = [num | num <- arr , _ <- [1..n]] -- list comprehension

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words
