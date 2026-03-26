# Part 1: Recursive Euclidean Algorithm
def gcd_recursive(a, b):
    if a == 0:
        return b
    return gcd_recursive(b % a, a)

# Part 2: Iterative GCD (for helper use)
def gcd_iterative(a, b):
    while b:
        a, b = b, a % b
    return a

# Part 3: Primitive Root Verification
def isPrimitiveRoot(g, n):
    s = set()
    # 1. Generate all powers of g modulo n
    for i in range(1, n):
        s.add(pow(g, i, n))
    
    # 2. Check if every i coprime to n exists in the generated set
    for i in range(1, n):
        if gcd_iterative(i, n) == 1:
            if i not in s:
                return False
    return True

# --- Execution ---
if __name__ == "__main__":
    # Demonstrate GCD
    print(f"GCD of 10 and 15: {gcd_recursive(10, 15)}")
    
    # Demonstrate Primitive Root Check
    n_val = int(input("Enter number n: "))
    g_val = int(input("Enter number g: "))

    if isPrimitiveRoot(g_val, n_val):
        print(f"SUCCESS: {g_val} is a primitive root of {n_val}")
    else:
        print(f"FAILURE: {g_val} is NOT a primitive root of {n_val}")