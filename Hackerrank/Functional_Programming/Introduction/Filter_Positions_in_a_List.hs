-- Name: Filter_Positions_in_a_List
-- WWWW: https://www.hackerrank.com/challenges/fp-filter-positions-in-a-list
-- Author: Jan Krepl

f :: [Int] -> [Int]
f lst = [lst !! i | i <- [1, 3 .. length(lst)]]

-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata
