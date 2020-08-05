def prime_factors(n):
    if type(n) is not int or n <=1:
        return []
    else:
        factors = []
        while n > 1:
            for divisor in range(2, n+1):
                if n % divisor == 0:
                    factors.append(divisor)
                    n = n // divisor
                    break
        return factors

if __name__ == "__main__":
    assert prime_factors(10) == [2,5]
    assert prime_factors(16769023) == [16769023]
#    assert prime_factors(1073676287) == [1073676287]

