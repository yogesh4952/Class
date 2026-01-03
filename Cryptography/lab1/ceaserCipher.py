def main():
    string = input("Please enter the plain text:")
    key = int(input("Please enter the key size:"))
    string = string.replace(" ","").upper()
    encrypted = []
    decrypted = []
 


    for i in range(len(string)):
        letter = string[i]
        cipher_char = chr(((ord(letter) - ord('A') + key ) % 26 + ord('A')))
        encrypted.append(cipher_char)
    print("The encrypted Msg is")
    print("".join(encrypted))

    #DECRYPTION
    for i in range(len(encrypted)):
        letter = encrypted[i]
        decrypted_char = chr((ord(letter)-ord('A')- key )%26 + ord('A'))
        decrypted.append(decrypted_char)
    print("The text after decryption")
    print("".join(decrypted))

if __name__ == '__main__':
    main()