-- Name: Evaluating_ex
-- WWWW: https://www.hackerrank.com/challenges/eval-ex
-- Author: Jan Krepl

import Control.Applicative
import Control.Monad
import System.IO

factorial 0 = 1
factorial n = n * factorial (n - 1)

approx x = sum[(x ** i)/factorial(i)| i <- [0 .. 9]]

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    forM_ [1..n] $ \a0  -> do
        x_temp <- getLine
        let x = read x_temp :: Double
        print (approx x)


