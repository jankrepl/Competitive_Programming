-- Name: Update_List
-- WWWW: https://www.hackerrank.com/challenges/fp-update-list
-- Author: Jan Krepl

-- Enter your code here. Read input from STDIN. Print output to STDOUT

f arr = [abs a | a <- arr]

-- This section handles the Input/Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata
