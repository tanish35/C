def max_winning_rounds(n, l, r, cards):
    max_rounds = 0
    start = 0
    
    while start < n:
        current_sum = 0
        valid_round_found = False
        for end in range(start, n):
            current_sum += cards[end]
            if l <= current_sum <= r:
                max_rounds += 1
                start = end + 1  # Move start to the next position after the current subarray end
                valid_round_found = True
                break
        if not valid_round_found:
            break  # If no valid round is found, exit the loop
    
    return max_rounds

# Example usage:
n = 5
l = 5
r = 6
cards = [1, 4, 2, 6, 4]
print(max_winning_rounds(n, l, r, cards))  # Output should be 2
