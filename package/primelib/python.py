import math

def divides(div, n):
    return (n % div == 0)

def is_prime(n):
    if type(n) is not int or n <=1:
        return False
    for div in range(2, math.floor(math.sqrt(n))+1):
        if divides(div, n):
            return False
    return True
