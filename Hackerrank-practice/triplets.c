#include<stdio.h>
int main()
{
	int n,i,j,k;
	int count=0;
	int input[100000];
	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&input[i]);

	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(input[i]<input[j] && input[j]<input[k])
					count++;	
			}
		}
	}
	
	printf("%d",count);

}
