#include<stdio.h>
long long fact(long long a);
int main()
{
	int input;
	scanf("%d",&input);
	printf("%lld",fact(input));
	return 0;
}

long long fact(long long a)
{
	if(a==1)
		return 1;
	else
		return a*fact(a-1);
}
