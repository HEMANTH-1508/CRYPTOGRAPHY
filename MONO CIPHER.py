if __name__ == "__main__":
    alpha = "abcdefghijklmnopqrstuvwxyz"
    key = "zyxwvutsrqponmlkjihgfedcba"
    a = input("Enter the plain text: ")
    print("Encrypted value: ", end="")
    for char in a:
        if char in alpha:
            index = alpha.index(char)
            print(key[index], end="")
        else:
            print(char, end="")
    print()
