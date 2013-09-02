#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count,diff;
	int num[100000];
	int result=0;
	int i,j;
	scanf("%d %d",&count,&diff);

	for(i=0;i<count;i++)
		scanf("%d",&num[i]);

	for(i=0;i<count-1;i++)
	{
		for(j=i+1;j<count;j++)
			result+=(abs(num[i]-num[j])-diff==0);
	}
	printf("%d",result);
}
