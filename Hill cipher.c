#include <stdio.h>
#include <string.h>
#include <math.h>

int isUpper(char *s)
{
    int i, len = strlen(s);
    for (i = 0; i < len; i++)
    {
    if (s[i] < 'A' || s[i] > 'Z')
    return 0;
    }
    return 1;
}
void matrixMultiply(int a[3][3], int b[3][1], int c[3][1], int n)
{
    int i, j, k, sum;
    for (i = 0; i < n; i++)
    {
    sum = 0;
    for (j = 0; j < n; j++)
    {
    sum += a[i][j] * b[j][0];
    }
    c[i][0] = sum % 26;
    }
}
void encrypt(char *plainText, int key[3][3], char *cipherText)
{
    int i, j, k, len;
    int plainVector[3][1], cipherVector[3][1];
    len = strlen(plainText);
    for (i = 0; i < len; i += 3)
    {
    for (j = 0; j < 3; j++)
    {
    if (i + j < len)
    plainVector[j][0] = plainText[i + j] - 'A';
    else
    plainVector[j][0] = 23;
    }
    matrixMultiply(key, plainVector, cipherVector, 3);
    {
    cipherText[i + k] = cipherVector[k][0] + 'A';
    }
    }

    cipherText[i] = '\0';
}

int main()
{
    char plainText[100], cipherText[100];
    int key[3][3] = {{17, 17, 5}, {21, 18, 21}, {2, 2, 19}};
    printf("Enter the plain text: ");
    scanf("%s", plainText);
    if (!isUpper(plainText))
    {
        printf("Invalid input. Only uppercase letters are allowed.\n");
        return -1;
    }
    encrypt(plainText, key, cipherText);
    printf("The cipher text is: %s\n", cipherText);
    return 0;
}
