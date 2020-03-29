import random

def check_prime(x):
    if x >= 2:
        for y in range(2, x):
            if not (x % y):
                return False
    else:
        return False
    return True


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def multiplicative_inverse(a, b):
   
    x = 0
    y = 1
    lx = 1
    ly = 0
    oa = a  
    ob = b  
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lx) = ((lx - (q * x)), x)
        (y, ly) = ((ly - (q * y)), y)
    if lx < 0:
        lx += ob  
    if ly < 0:
        ly += oa  
    return lx


def get_mod_expo(base, exponent, modulus):
    result = 1
    while exponent:
        exponent, d = exponent // 2, exponent % 2
        if d:
            result = result * base % modulus
        base = base * base % modulus
    return result


def generate_keypair(p, q):
    if not (check_prime(p) and check_prime(q)):
        raise ValueError('Both numbers must be prime.')
    elif p == q:
        raise ValueError('p and q cannot be equal!')
   
    n = p * q
    print("Value of n (where, n = p * q) is: ", n)

  
    phi = (p-1)*(q-1)
    print("Value totient of phi(n) (where, phi(n) = (p-1)*(q-1)) is: ", phi)
    print("Enter e such that is co-prime to ", phi, ": ")
    e = int(input())

   
    g = gcd(e, phi)
    if g != 1:
        print("The number you entered is not co-prime, Please enter e such that is co-prime to ", phi, ": ")
        e = int(input())
    print("Value of e entered is: ", e)

    
    d = multiplicative_inverse(e, phi)
    print("Value of d is: ", d)
    return (e, n), (d, n)

def encrypt(public_key, to_encrypt):

    key, n = public_key
    cipher = get_mod_expo(to_encrypt, key, n)
    return cipher


def decrypt(private_key, to_decrypt):
    key, n = private_key
    decrypted = get_mod_expo(to_decrypt, key, n)
    return decrypted

print("\n######## RSA Encryption/Decryption Algorithm #########\n")
p = int(input("Enter a prime number (p: 7, 11, 23, etc): "))
q = int(input("Enter another prime number (q: 5, 13, 19, etc [Not same as above]): "))
print("Prime numbers entered, p: ", p, " and q: ", q)

print("Generating Public/Private key-pairs!")
public, private = generate_keypair(p, q)
print("Your public key is ", public, " and your private key is ", private)

message = int(input("Enter the message to be encrypted: "))
print("Message to be encrypted (M): ", message)

encrypted_msg = encrypt(public, message)
print("Encrypted message (C): ", encrypted_msg)

decrypted_msg = decrypt(private, encrypted_msg)
print("Message decrypted (M'): ", message)