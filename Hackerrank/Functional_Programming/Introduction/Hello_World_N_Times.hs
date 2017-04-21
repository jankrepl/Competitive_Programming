-- Name: Hello_World_N_Times
-- WWWW: https://www.hackerrank.com/challenges/fp-hello-world-n-times
-- Author: Jan Krepl

function_1 1 = putStrLn "Hello World"
function_1 n = do
        putStrLn "Hello World" 
        function_1 (n - 1)

main = do
   n <- readLn
   function_1 n