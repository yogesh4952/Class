def encipher():
    input_text = input("Enter Plain Text:").replace(" ","").upper()
    key = input("Enter the key value:").replace(" ","").upper()
    encrypted = []
    j = 0
    for i in range(len(input_text)):
        if j >= len(key):
            j = 0
        char = input_text[i]
        key_char = key[j]
        cypher_char = chr((ord(char) + ord(key_char)) % 26 + 65)
        encrypted.append(cypher_char)
        j+=1
    print("".join(encrypted))


def decipher():
    input_text = input("Enter Cipher Text:").replace(" ","").upper()
    key = input("Enter the key value:").replace(" ","").upper()
    decrypted = []
    j = 0
    for i in range(len(input_text)):
        if j >= len(key):
            j = 0
        char = input_text[i]
        key_char = key[j]
        cypher_char = chr((ord(char) - ord(key_char)) % 26 + 65)
        decrypted.append(cypher_char)
        j+=1
    print("".join(decrypted))

if __name__ == '__main__':
    
    while 1:
        print("Press 1 to encrypt Text.")
        print("Press 2 to decrypt Text.")
        print("Press 3 to exit.")
        choice = int(input("Please input your choice:"))

        match choice:
            case 1:
                encipher()
            case 2:
                decipher()
            case 3: 
                break

            case _:
                print("Invalid Input.")