#include<stdio.h>
#include<string.h>
int main(){
	char
	alp[53]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char p[100];
	int key;
	printf("enter the plain text:");
	scanf("%s",&p);
	printf("enter the key value:");
	scanf("%d",&key);
	key=key%26;
	printf("cypher text is:");
	for(int i=0;i<strlen(p);i++){
		for(int j=0;j<26;j++){
			if(p[i]==alp[j]){
				printf("%c",alp[j+key]);
				break;
			}
		}
	}
	printf("\nplain text is:%s",p);
}
