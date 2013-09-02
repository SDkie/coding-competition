#include<stdio.h>
int main(){

	int i, n, k,j;
	int c[100];
	long long result=0;
	int temp,p;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%d", &(c[i]));
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(c[j]<c[j+1])
			{
				temp=c[j],c[j]=c[j+1],c[j+1]=temp;	
			}	
		}
	}	

	//for(i=0;i<n;i++)
	//	printf("%d ",c[i]);

	for(i=0,j=0;i<n;j++)
	{
		for(p=0;p<k&&i<n;p++)
			result+=(j+1)*c[i++];
	}	
   	
	printf("%lld\n", result);
}
