def gcd(a,b):
    while(b):
        a,b = b,a%b
    return a

a=int(input("Enter first num: "))
b=int(input("Enter second num: "))
if gcd(a,b)==1:
    print("numbers are relatively prime")
else:
    print("numbers are not relatively prime")
