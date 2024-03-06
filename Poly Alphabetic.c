#include<stdio.h>
#include<string.h>
#include<string.h>
int main(){
	char p[100],key[100],s[100];
	char
	alp[27]="abcdefghijklmnopqrstuvwxyz";
	printf("enter the plain text:");
	scanf("%s",&p);
	printf("enter the key value:");
	scanf("%s",&key);
	if(strlen(p)>strlen(key)){
		int i=0,x=0;
		while(i<strlen(p)){
			s[i]=key[x];
			x++;
			i++;
			if(x==strlen(key)){
				x=0;
			}
		}
	}
	else{
		strcpy(s,key);
	}
	for(int i=0;i<strlen(p);i++){
		int su=0;
		for(int j=0;j<26;j++){
			if(p[i]==alp[j]){
				su+=j;
			}
			if(s[i]==alp[j]){
				su+=j;
			}
		}
		printf("%c",alp[su%26]);
	}
}
