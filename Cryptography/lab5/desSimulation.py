from pyDes import des ,CBC,PAD_PKCS5
import binascii

key = "01234567"  # 64 bit key for DES
data="Hello123"
cipher = des(key, CBC, key, pad=None, padmode=PAD_PKCS5)

encrypted_data = cipher.encrypt(data)
hex_encrypted_data = binascii.hexlify(encrypted_data)
print("Encrypted:", hex_encrypted_data.decode())