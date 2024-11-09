def fibonacci_divisible_by(x, y):
    fib_sequence = []
    fib=[]
    a, b = 0, 1
    fib.append(a);
    fib.append(b);
    
    while len(fib_sequence) < x:
        if a % y == 0:
            fib_sequence.append(a)
        a, b = b, a + b
        fib.append(b)
    
    for num in fib_sequence:
        print(num)
    print(fib)

# Example usage:
fibonacci_divisible_by(5, 3)  # Prints the first 5 Fibonacci numbers divisible by 3
