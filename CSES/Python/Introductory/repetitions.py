dna = input()

longest = 1
curr = 1
prev = dna[0]
for i in range(1,len(dna)):
    if dna[i] != dna[i-1]:
        curr = 0
    curr += 1
    longest = max(longest,curr)

print(longest)