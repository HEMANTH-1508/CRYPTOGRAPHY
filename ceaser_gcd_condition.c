#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() 
{
    char plaintext[100], ciphertext[100];
    int a, b, i;

    // Input parameters a and b
    printf("Enter value of a (must be relatively prime to 26): ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    // Validate the value of a
    if (a <= 0 || a >= 26 || gcd(a, 26) != 1) {
        printf("Invalid value of 'a'. It must be relatively prime to 26.\n");
        return 1;
    }

    // Validate the value of b
    if (b < 0 || b >= 26) {
        printf("Invalid value of 'b'. It must be between 0 and 25 (inclusive).\n");
        return 1;
    }

    // Input plaintext
    printf("Enter plaintext: ");
    scanf(" %[^\n]", plaintext);

    // Encrypt the plaintext
    for (i = 0; plaintext[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (isupper(plaintext[i])) {
            ciphertext[i] = ((a * (plaintext[i] - 'A') + b) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(plaintext[i])) {
            ciphertext[i] = ((a * (plaintext[i] - 'a') + b) % 26) + 'a';
        }
        // Keep non-alphabetic characters unchanged
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to find the greatest common divisor (gcd) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
