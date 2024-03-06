#include<stdio.h>
#include<string.h>

int main() 
{
    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char mono[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m'};
    char pt[100], ct[100] = "";
    
    printf("\nENTER PLAIN TEXT : ");
    scanf("%s", pt);
    
    char *ptr = pt;
    while(*ptr != '\0') 
    {
        char ch = *ptr;
        for(int i = 0; i < 26; i++) 
        {
            if(ch == alpha[i]) 
            {
                strncat(ct, &mono[i], 1);
            }
        }
        ptr++;
    }
    
    printf("\nCIPHER TEXT : %s\n", ct); 
    

    return 0;
}


//OUTPUT
//PT=HELLO
//CT=ITSSG