def find_winner(test_cases):
    results = []
    
    for test in test_cases:
        n, piles = test
        total_sum = sum(piles)
        
        if total_sum % 2 == 0:
            results.append("Bob")
        else:
            results.append("Alice")
    
    return results

# Reading input
t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    piles = list(map(int, input().split()))
    test_cases.append((n, piles))

# Processing and printing output
results = find_winner(test_cases)
for result in results:
    print(result)

