import random

def generate_random_numbers(filename, quantity=1000):
    """
    Generates a list of random numbers between 0 and 1 
    and saves them to a file, one per line.
    """
    try:
        with open(filename, 'w') as f:
            for _ in range(quantity):
                # Generate a random float and format to 5 decimal places
                # 5 decimal places ensures compatibility with the Poker test logic
                num = random.random()
                f.write(f"{num:.5f}\n")
        print(f"Successfully generated {quantity} random numbers in '{filename}'.")
    except Exception as e:
        print(f"Error writing to file: {e}")

if __name__ == "__main__":
    file_name = "random_numbers.txt"
    try:
        qty_input = input("Enter the number of random values to generate (default 1000): ").strip()
        qty = int(qty_input) if qty_input else 1000
        generate_random_numbers(file_name, qty)
    except ValueError:
        print("Invalid input. Using default 1000.")
        generate_random_numbers(file_name, 1000)
