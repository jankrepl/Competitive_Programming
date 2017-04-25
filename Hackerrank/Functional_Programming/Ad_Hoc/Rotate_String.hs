-- Name: Rotate_String
-- WWW: https://www.hackerrank.com/challenges/rotate-string
-- Author: Jan Krepl


-- import Data.List -- not necessary

-- Rotate a list by nelements .. not a recursion
rotate :: Int -> String -> String
rotate _ [] = []
rotate n xs = zipWith const (drop n (cycle xs)) xs

-- print_all rotations
rotations_all xs = do
        let rots = [1 .. length xs]
        let result = [rotate i xs ++ " " | i <- rots] 
        mapM_ (putStr) result
        putStr "\n"
        
main = do
  n <- getLine
  input <- sequence (replicate (read n :: Int) getLine) -- create a string of inputs
  mapM_ rotations_all input
