-- Calculates the factorial of a number
fatorial :: Integer -> Integer
fatorial 0 = 1
fatorial n = n * fatorial (n - 1)

-- Usage:
main = do
    let n = 5
    putStrLn ("The factorial of " ++ show n ++ " is " ++ show (fatorial n))