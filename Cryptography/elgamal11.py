# elgamal
import random

def is_prime(num):
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(num**0.5) + 1, 2):
        if num % i == 0:
            return False
    return True

def generate_key(p):
    g = 2  # Fixed primitive root instead of random
    x = random.randint(2, p - 2)   # Private key
    y = pow(g, x, p)               # Public key component
    return (g, p, y, x)

def encrypt(plain_text, public_key):
    g, p, y, _ = public_key
    k = random.randint(2, p - 2)   # Random session key
    c1 = pow(g, k, p)
    s = pow(y, k, p)
    c2 = [(ord(char) * s) % p for char in plain_text]
    return (c1, c2)

def decrypt(ciphertext, private_key):
    g, p, _, x = private_key
    c1, c2 = ciphertext
    s = pow(c1, x, p)
    s_inv = pow(s, -1, p)          # Modular inverse
    plain_text = ''.join([chr((c * s_inv) % p) for c in c2])
    return plain_text

# Main Program
while True:
    p = int(input("Enter a prime number (Greater than 2): "))
    if is_prime(p):
        break
    else:
        print("Invalid input. Please enter a prime number greater than 2.")

receiver_key = generate_key(p)

print("Receiver's Public Key (g, p, y):", receiver_key[:3])

message = input("Enter the message to be encrypted: ")

ciphertext = encrypt(message, receiver_key)
print("Ciphertext (c1, c2):", ciphertext)

decrypted_message = decrypt(ciphertext, receiver_key)
print("Decrypted Message:", decrypted_message)