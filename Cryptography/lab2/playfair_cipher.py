def playfair_cipher(plaintext,key,node):
    alphabet = "abcdefghiklmnopqrstuvwxyz"
    key  = key.lower().replace(' ','').replace('j','i')
    key_square = ''
    for letter in key + alphabet:
        if letter not in key_square:
            key_square+=letter
            
    plaintext = plaintext.lower().replace(' ','').replace('j','i')
    if len(plaintext) %2 ==1:
        plaintext +='x'
    diagraphs = [plaintext[i:i+2] for i in range(0,len(plaintext),2)]
        
    def encrypt(diagraph):
        a,b=diagraph
        row_a,col_a = divmod(key_square.index(a),5)
        row_b,col_b = divmod(key_square.index(b),5)
        if row_a == row_b:
            col_a = (col_a +1) %5
            col_b = (col_b +1) %5
        elif col_a == col_b:
            row_a = (row_a +1) %5
            row_b = (row_b +1) %5
        else:
            col_a,col_b = col_b,col_a
        return key_square[row_a*5 + col_a] + key_square[row_b*5 + col_b]
    
    def decrypt(diagraph):
        a,b=diagraph
        row_a,col_a = divmod(key_square.index(a),5)
        row_b,col_b = divmod(key_square.index(b),5)
        if row_a == row_b:
            col_a = (col_a -1) %5
            col_b = (col_b -1) %5
        elif col_a == col_b:
            row_a = (row_a -1) %5
            row_b = (row_b -1) %5
        else:
            col_a,col_b = col_b,col_a
        return key_square[row_a*5 + col_a] + key_square[row_b*5 + col_b]
    
    # Encrypt or decrypt the plaintext
    result = ''
    for diagraph in diagraphs:
        if node == 'encrypt':
            result += encrypt(diagraph)
        elif node == 'decrypt':
            result += decrypt(diagraph)
            
    return result

# FUnction to display key table
def display_key_table(key):
    key = key.lower().replace(' ','').replace('j','i')
    key_square = ''
    for letter in key + "abcdefghiklmnopqrstuvwxyz":
        if letter not in key_square:
            key_square+=letter
    for i in range(0,25,5):
        print(' '.join(key_square[i:i+5]))

# Example usage

def main():
    key = input("Enter the key: ")
    display_key_table(key)
    plaintext = input("Enter the plaintext: ")
    ciphertext = playfair_cipher(plaintext, key, 'encrypt')
    print("Ciphertext:", ciphertext)
    decrypted_text = playfair_cipher(ciphertext, key, 'decrypt')
    print("Decrypted text:", decrypted_text)
    
if __name__ == "__main__":
    main()