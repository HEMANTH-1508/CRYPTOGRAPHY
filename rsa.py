if __name__ == "__main__":
    p = int(input("Enter the value of P: "))
    q = int(input("Enter the value of q: "))
    e = int(input("Enter the value of e: "))
    m = int(input("Enter the value of m: "))

    n = p * q
    dn = (p - 1) * (q - 1)

    for i in range(1, dn):
        if (e * i) % dn == 1:
            d = i
            break

    x = pow(m, e)
    c = x % n
    print("Encrypted is", c)

    de = pow(c, d)
    print("Decrypted is", de % n)
