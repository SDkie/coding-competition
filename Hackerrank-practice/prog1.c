
#include<stdio.h>
#define MAX 20
void partition(int a[MAX],int low,int high);
void merge(int a[MAX],int l,int m,int h);
int main()
{
	int a[MAX],i,size,diff,result=0;
	scanf("%d %d",&size,&diff);
	for(i=0;i<size;i++)
        	scanf("%d",&a[i]);	
	partition(a,0,size-1);
	for(i=0;i<size-1;i++)
	{
		result+=(a[i+1]-a[i]==diff);
	}
	printf("%d",result);
	return 0;
}

void partition(int a[MAX],int i,int j)
{
	int k;
	if(i<j)
	{
		k=(i+j)/2;
		partition(a,i,k);
		partition(a,k+1,j);
		merge(a,i,k,j);	
	}
}
void merge(int a[MAX],int l,int m,int h)
{
	int c[MAX],i=l,j=m+1,count=0;
	while(i<=m&&j<=h)
	{
		if(a[i]<=a[j])
			c[count++]=a[i++];
		else
			c[count++]=a[j++];
	}
	while(i<=m)
		c[count++]=a[i++];	

	while(j<=h)
		c[count++]=a[j++];

	for(i=l,j=0;i<=h;)
		a[i++]=c[j++];
}
