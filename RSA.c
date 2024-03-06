#include<stdio.h>
#include<math.h>
int main(){
int n,p,q,dn,e,d,m;
printf("Enter the value of P:");
scanf("%d",&p);
printf("enter the value of q:");
scanf("%d",&q);
printf("Enter the value of e:");
scanf("%d",&e);
printf("Enter the value of m:");
scanf("%d",&m);
n=p*q;
dn=(p-1)*(q-1);
for(int i=1;i<dn;i++)
{
if((e%dn)*(i%dn)%dn==1)
{
d=i;
break;
}
}
int x=pow(m,e);
int c =x%n;
printf("Encrypted is %d",c);
int de=pow(c,d);
printf("\n Decrypted is %d",de%n);
}
