def des_encrypt(plain_text, key):
    return plain_text  

def print_binary(num):
    binary_string = format(num, '064b')
    for i in range(0, 64, 8):
        print(binary_string[i:i+8], end=" ")
    print()

def main():
    plain_text = int(input("Enter the 64-bit plaintext: "), 16)
    key = int(input("Enter the 64-bit encryption key: "), 16)
    cipher_text = des_encrypt(plain_text, key)
    print("\nPlaintext: ", end="")
    print_binary(plain_text)
    print("Key: ", end="")
    print_binary(key)
    print("Ciphertext: ", end="")
    print_binary(cipher_text)

if __name__ == "__main__":
    main()
