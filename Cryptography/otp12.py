#OTP GENERATION

import pyotp 
user_id = pyotp.random_base32()
totp = pyotp.TOTP(user_id)



otp = totp.now()
print("User ID:",user_id)
print("Generated OTP:",otp)

user_input_otp = input("Enter the OTP:")

is_valid_otp = totp.verify(user_input_otp)
if is_valid_otp:
    print("OTP is valid.")
else: 
    print("OTP is not valid.")