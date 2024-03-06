#include<stdio.h>
#include<string.h>

int main()
{
    char pt[100];
    char enc[100] = "";
    int key, l, index = 0,i;
    printf("\nEnter plaintext: ");
    scanf("%s",&pt);
    l = strlen(pt);
    printf("Enter key: ");
    scanf("%d", &key);
    for (i = 0; i < key; i++) 
    {
        int j = i;
        int increment = (key - 1) * 2;

        while (j < l) 
        {
            enc[index++] = pt[j];
            if (i != 0 && i != key - 1 && j + increment - 2 * i < l) 
            {
                enc[index++] = pt[j + increment - 2 * i];
            }
            j += increment;
        }
    }
    printf("Encrypted text: %s\n", enc);
}


//OUTPUT
//PT=HELLO
//KEY=2
//CT=HLOEL