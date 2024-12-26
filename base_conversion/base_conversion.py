def base_conversion(num, n):
    if num == 0:
        return "0"
    
    digits = "0123456789ABCDEF"
    li = []
    
    while num != 0:
        li.append(digits[num % n])
        num //= n
    
    return "".join(reversed(li))



def to_decimal(num, n):
    num = str(num)
    ans = 0
    for i in range(len(num)):
        digit = "0123456789ABCDEF".index(num[len(num)-1-i]) # ~의 인덱스를 반환, li.index("A") -> "A"의 인덱스 10 반환
        ans += digit * (n ** i)
    return ans



print("=====================================")

print(base_conversion(3, 2))
print(base_conversion(10, 2))
print(base_conversion(166, 16))
print(base_conversion(166, 11))
print(base_conversion(100000, 16))

print("=====================================")

print(to_decimal("11", 2))
print(to_decimal("1010", 2))
print(to_decimal("A6", 16))
print(to_decimal("142", 11))
print(to_decimal("186A0", 16))

print("=====================================")