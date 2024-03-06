#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char key[] = "PLAYFAIREXAMPLE";
    char message[] = "HELLO";
    char keySquare[5][5];
    char preparedMessage[100]; 
    char encryptedMessage[100];
    int i, j, k, l, m, n, p, q;

    k = 0;
    for (i = 0; i < strlen(message); i++) 
    {
        if (isalpha(message[i])) 
        {
            preparedMessage[k++] = toupper(message[i]);
        }
    }
    preparedMessage[k] = '\0';

    for (i = 0; i < strlen(preparedMessage); i++) 
    {
        if (preparedMessage[i] == 'J') 
        {
            preparedMessage[i] = 'I';
        }
    }

    k = 0;
    for (i = 0; i < strlen(preparedMessage) - 1; i += 2) 
    {
        if (preparedMessage[i] == preparedMessage[i + 1]) 
        {
            memmove(&preparedMessage[i + 1], &preparedMessage[i], strlen(&preparedMessage[i]) + 1);
            preparedMessage[i + 1] = 'X';
        }
    }

    if (strlen(preparedMessage) % 2 != 0) {

        strcat(preparedMessage, "X");
    }

    k = 0;
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            keySquare[i][j] = key[k];
            k++;
        }
    }

    k = 0;
    while (k < strlen(preparedMessage)) 
    {
        for (i = 0; i < 5; i++) 
        {
            for (j = 0; j < 5; j++) 
            {
                if (keySquare[i][j] == preparedMessage[k]) 
                {
                    l = i;
                    m = j;
                }
                if (keySquare[i][j] == preparedMessage[k + 1]) 
                {
                    n = i;
                    p = j;
                }
            }
        }

        if (l == n) 
        {
            encryptedMessage[k] = keySquare[l][(m + 1) % 5];
            encryptedMessage[k + 1] = keySquare[n][(p + 1) % 5];
        } 
        else if (m == p) 
        {
            encryptedMessage[k] = keySquare[(l + 1) % 5][m];
            encryptedMessage[k + 1] = keySquare[(n + 1) % 5][p];
        } 
        else 
        {
            encryptedMessage[k] = keySquare[l][p];
            encryptedMessage[k + 1] = keySquare[n][m];
        }

        k += 2;
    }
    encryptedMessage[k] = '\0';

    printf("Encrypted message: %s\n", encryptedMessage);

}


//OUTPUT
//