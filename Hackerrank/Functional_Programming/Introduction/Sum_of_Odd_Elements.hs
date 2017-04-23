-- Name: Sum_of_Odd_Elements
-- WWWW: https://www.hackerrank.com/challenges/fp-sum-of-odd-elements
-- Author: Jan Krepl

f arr = sum[a | a <- arr, odd a]

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata
