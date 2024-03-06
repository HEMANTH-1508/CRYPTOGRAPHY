def main():
    a = int(input("Enter the value of a: "))
    q = int(input("Enter the value of q: "))
    xa = int(input("Enter the value of xa: "))
    xb = int(input("Enter the value of xb: "))

    x = pow(a, xa)
    ya = x % q
    print("Value of ya:", ya)

    y = pow(a, xb)
    yb = y % q
    print("Value of yb:", yb)

    m = pow(yb, xa)
    ka = m % q
    print("Value of ka:", ka)

    n = pow(ya, xb)
    kb = n % q
    print("Value of kb:", kb)

if __name__ == "__main__":
    main()

