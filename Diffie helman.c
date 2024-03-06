#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a,q,xa,xb,ya,yb,x,y,ka,kb,m,n;
	printf("enter the value of a:");
	scanf("%d",&a);
	printf("enter the value of q:");
	scanf("%d",&q);
	printf("enter the value of xa:");
	scanf("%d",&xa);
	printf("enter the value of xb:");
	scanf("%d",&xb);
	x=pow(a,xa);
	ya=x%q;
	printf("value of ya: %d",ya);
	y=pow(a,xb);
	yb=y%q;
	printf("\nvalue of yb: %d",yb);
	m=pow(yb,xa);
	ka=m%q;
	printf("\nvalue of ka: %d",ka);
	n=pow(ya,xb);
	kb=n%q;
	printf("\nvalue of kb: %d",kb);
}
