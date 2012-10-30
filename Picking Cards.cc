#include<iostream>
using namespace std;
int main()
{
	int testcases;
	cin>>testcases;
	int count,count1,j;
	for(j=0;j<testcases;j++)
	{
	cin>>count;
	long long ans;
	int pass;
	int i;
	int N[50000]={0};
	int temp;
	for(i=0;i<count;i++)
	{	
		cin>>temp;
		N[temp]++;
	}
	count1=count;
	pass=0;
	ans=1;
	do
	{
		if(N[pass]==0)
		{
			ans=0;
			count1=1;
		}
		else
		{
			ans*=N[pass];
			N[pass+1]+=(N[pass]-1);
		}
		pass++;
		count1--;
		ans%=1000000007;
	}while(count1);
	cout<<ans%1000000007<<"\n";
	}
return 0;
}
