def gcd(a, b):
    while a != 0:
        a, b = b % a, a
    return b if b != 1 else "1, There is no common divisor except 1"

print(gcd(14, 24)) 
