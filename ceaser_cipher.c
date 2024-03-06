#include <stdio.h>
#include <string.h>

int main() 
{
    char pt[100], ct[100];
    int k,i=0;

    printf("\nEnter Plain Text: ");
    scanf("%s", pt);
    printf("Enter Key: ");
    scanf("%d", &k);

    char *ptr = pt;
    while (*ptr != '\0') 
    {
        char ch = *ptr;
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = ((ch - 'A' + k) % 26) + 'A';
        }
        else if (ch >= 'a' && ch <= 'z') 
        {
            ch = ((ch - 'a' + k) % 26) + 'a';
        }
        ct[i] = ch;
        ptr++;
        i++;
    }
    ct[i] = '\0'; 

    printf("Cipher Text: %s\n", ct);

    return 0;
}


//OUTPUT
//PT=HELLO
//KEY=3
//CT=KHOOR