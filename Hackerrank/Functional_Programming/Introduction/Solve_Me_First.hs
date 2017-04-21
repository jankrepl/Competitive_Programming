-- Name: Solve_Me_First
-- WWWW: https://www.hackerrank.com/challenges/fp-solve-me-first
-- Author: Jan Krepl

solveMeFirst a b = a + b

main = do
    val1 <- readLn
    val2 <- readLn
    let sum = solveMeFirst val1 val2
    print sum
