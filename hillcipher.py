def isUpper(s):
    for char in s:
        if not 'A' <= char <= 'Z':
            return False
    return True

def matrix_multiply(a, b, c, n):
    for i in range(n):
        sum = 0
        for j in range(n):
            sum += a[i][j] * b[j][0]
        c[i][0] = sum % 26

def encrypt(plain_text, key):
    cipher_text = ''
    n = 3
    len_plain = len(plain_text)
    for i in range(0, len_plain, 3):
        plain_vector = [[0] for _ in range(3)]
        cipher_vector = [[0] for _ in range(3)]
        for j in range(3):
            if i + j < len_plain:
                plain_vector[j][0] = ord(plain_text[i + j]) - ord('A')
            else:
                plain_vector[j][0] = 23
        matrix_multiply(key, plain_vector, cipher_vector, n)
        for k in range(3):
            cipher_text += chr(cipher_vector[k][0] + ord('A'))
    return cipher_text

if __name__ == "__main__":
    key = [[17, 17, 5], [21, 18, 21], [2, 2, 19]]
    plain_text = input("Enter the plain text: ").upper()
    if not isUpper(plain_text):
        print("Invalid input. Only uppercase letters are allowed.")
    else:
        cipher_text = encrypt(plain_text, key)
        print("The cipher text is:", cipher_text)
