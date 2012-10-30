#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct topic
{
	int tid;
	float x,y;
	long double dist;
};
struct question
{
	int qid;
	int ntid;
	int tid[1000];
	
};
struct queries
{
	char q;
	int result;
	float x,y;
};
int main()
{
	int t,q,n;
	cin>>t>>q>>n;
	struct topic top[1000];
	struct question ques[1000];
	struct queries quri[1000];
	
	long double tresult[1000];
	int tresultid[1000];
	
	int i,j,k,id;
	for(i=0;i<t;i++)
	{
		cin>>top[i].tid>>top[i].x>>top[i].y;
	}
	for(i=0;i<q;i++)
	{
		cin>>ques[i].qid>>ques[i].ntid;
		for(j=0;j<ques[i].ntid;j++)
		{
			cin>>ques[i].tid[j];
		}
	}
	for(i=0;i<n;i++)
	{
		cin>>quri[i].q>>quri[i].result>>quri[i].x>>quri[i].y;
	}
	int count;
	long double tempf;
	int tempi;
	int x,y;
	for(i=0;i<n;i++)
	{
		if(quri[i].q=='t')//start of test case
		{
			
			count=quri[i].result;//num of points requred;
			x=quri[i].x;
			y=quri[i].y;
			for(j=0;j<t;j++)
			{
				tresult[j]=((top[j].x-x)>0?(top[j].x-x):-(top[j].x-x)+(top[j].y-y)>0?(top[j].y-y):-(top[j].y-y));
				tresultid[j]=j;
			}
			int flag;
			for(j=0;j<count;j++)
			{
				for(k=0;k<t;k++)
				{
					flag=0;
					if(tresult[k]>tresult[k+1])
					{
						tempf=tresult[k+1];
						tresult[k+1]=tresult[k];
						tresult[k]=tempf;
						
						tempi=tresultid[k+1];
						tresultid[k+1]=tresultid[k];
						tresultid[k]=tempi;
						flag=1;
					}
					if(flag==0)
						k=t;
				}
			}
			for(j=0;j<count;j++)
				cout<<tresultid[j]<<" ";
		}
		else//start of test case
		{
			int mask[1000]={0};
			int qresultid[1000]={0};
			int qcount=0;
			count=quri[i].result;//num of points requred;
			x=quri[i].x;
			y=quri[i].y;
			for(j=0;j<t;j++)
			{
				tresult[j]=((top[j].x-x)>0?(top[j].x-x):-(top[j].x-x)+(top[j].y-y)>0?(top[j].y-y):-(top[j].y-y));
				tresultid[j]=j;
			}
			int flag=0;
			//
			for(j=0;flag==0;j++)
			{				
				if(count==0||j==t)
					flag=1;	
				for(k=j+1;k<t;k++)
				{
					if(tresult[j]>tresult[k])
					{
						
						tempf=tresult[k];
						tresult[k]=tresult[j];
						tresult[j]=tempf;
						
						tempi=tresultid[k];
						tresultid[k]=tresultid[j];
						tresultid[j]=tempi;
					}	
				}
				id=tresultid[j];
				qcount=0;
			//	cout<<"{"<<tresult[j]<<"}";
				for(int it=0;it<q;it++)
				{
					for(int itt=0;itt<ques[it].ntid;itt++)
					{
						if(mask[ques[it].qid]!=1&&ques[it].tid[itt]==id)
						{
							qresultid[qcount++]=ques[it].qid;
							mask[ques[it].qid]=1;
						}
					}
				}
				int flag1,temp;
				for(int it=0;it<qcount;it++)
				{
					flag1=1;
					for(int itt=1;itt<(qcount-it);itt++)
					{
						if(qresultid[it]<qresultid[itt])
						{
							temp=qresultid[it];
							qresultid[it]=qresultid[itt];
							qresultid[itt]=temp;
							flag1=0;
						}
					}
					if(flag1==1)
						it=qcount;	
				}
				for(int it=0;it<qcount;it++,count--)
				cout<<qresultid[it]<<" ";
			
			}
		}
		cout<<"\n";
	}
	return 0;
}
