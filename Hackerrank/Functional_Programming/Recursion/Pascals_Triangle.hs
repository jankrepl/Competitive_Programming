-- Name: Pascals_Triangle
-- WWWW: https://www.hackerrank.com/challenges/pascals-triangle
-- Author: Jan Krepl


factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial(n - 1)

nchoosek :: Int -> Int -> Int
nchoosek n k = (factorial(n)) `quot` (factorial(k)*factorial(n-k))



pascal 0 = print 1
pascal n = do
        let temp = [nchoosek n i | i <- [0 .. n]]
        pascal (n - 1)
        putStrLn $ unwords . map show $ temp

main = do
    n <- readLn :: IO Int
    pascal (n - 1)



