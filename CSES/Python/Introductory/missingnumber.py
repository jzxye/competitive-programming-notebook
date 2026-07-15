
n = int(input())

nums = [int(x) for x in input().split()]
sum = 0
for x in nums:
    sum += x

answer = n*(n+1)//2 - sum
print(answer)