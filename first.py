# 3 - B

array = [int(i) for i in input().split()]

sum1 = 0
for i in array:
    sum1 += i

no_of_zeroes = 0
for i in array:
    if i==0:
        no_of_zeroes += 1
        i = 1

sum2 = 0
for i in array:
    sum2 += i

print(no_of_zeroes)