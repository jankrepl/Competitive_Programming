-- Name: String_Mingling
-- WWW: https://www.hackerrank.com/challenges/string-mingling
-- Author: Jan Krepl


-- Enter your code here. Read input from STDIN. Print output to STDOUT


-- n is the index 
func_1 s p size n = do         
           putStr [s!!n, p!!n]
           if n /= (size - 1)
                then (func_1 s p size (n + 1))
                else return ()
               
func_2 "" "" = [] -- base case
func_2 a b = (head a) : (head b) : (func_2 (tail a) (tail b)) -- induction step



main = do
    s <- getLine
    p <- getLine
    
    putStrLn $ func_2 s p -- solution 2
    
    -- let size = length s -- solution 1
    -- func_1 s p size 0