#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], keyword[100], ciphertext[100];
    int i, j;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter keyword: ");
    scanf("%s", keyword);

    int plaintextLen = strlen(plaintext);
    int keywordLen = strlen(keyword);
    for(i = keywordLen, j = 0; i < plaintextLen; ++i, ++j) 
    {
        keyword[i] = keyword[j];
    }
    keyword[i] = '\0'; 

    for(i = 0; i < plaintextLen; ++i) 
    {
        if(isalpha(plaintext[i])) 
        {
            int offset = tolower(keyword[i]) - 'a';

            if(isupper(plaintext[i])) 
            {
                ciphertext[i] = (plaintext[i] - 'A' + offset) % 26 + 'A';
            }
            else 
            {
                ciphertext[i] = (plaintext[i] - 'a' + offset) % 26 + 'a';
            }
        }
        else 
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}


//OUTPUT
//PT=SHEISINTELLIGENT
//KEY=PASCAL
//CT=HHWKSTCTWNLTVEFV