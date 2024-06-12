import random

def generate_sum_sequence(filename, num_elements, limit=10**9):
    with open(filename, 'w') as f:
        numbers = []
        current_sum = 0
        for i in range(num_elements):
            if current_sum > limit:
                new_number = limit
            else:
                if i == 0:
                    new_number = random.randint(1, limit//100000000)
                else:
                    new_number = current_sum
            
            # Add the new number to the list and update the current sum
            numbers.append(new_number)
            current_sum += new_number
        
        # Write the number of elements
        f.write(f"{num_elements}\n")
        # Write all numbers to the file
        for number in numbers:
            f.write(f"{number} ")
        f.write("\n")

# Generate a sequence with 10^4 elements
generate_sum_sequence("large_test_case.txt", 10**4)
