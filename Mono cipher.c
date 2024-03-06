#include<stdio.h>
#include<string.h>
int main(){
	char
	alpha[]="abcdefghijklmnopqrstuvwxyz";
	char key[]="zyxwvutsrqponmlkjihgfedcba";
	char a[100];
	printf("enter the plain text:");
	scanf("%[^\n]s",a);
	printf("encrpted value:");
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<26;j++){
			if(a[i]==alpha[j]){
				a[i]=key[j];
				break;
			}
		}
		printf("%c",a[i]);
	}
}
