#include<stdio.h>
void process();
int TT;			//max 25
int n,m,k;		// n - 2000 
struct inputgraph temp;
struct inputgraph
{
	short int i;
	short int j;
	 int c;
}ig[2000000];   //increase latter

int main()
{
	int p,q;
	scanf("%d",&TT);
	for(q=1;q<=TT;q++)
	{
		scanf("%d %d %d",&n,&m,&k);
		for(p=1;p<=m;p++)
			scanf("%hd %hd %d:",&ig[p].i,&ig[p].j,&ig[p].c);	
			
		if(k>=n)
			printf("%d\n",0);
		else if(k==0||(k+m<n-1))
			printf("Impossible!\n");
		else
			process();
	}
	return 0;
}

void pushup(int poss)
{
		int mini=ig[poss].c;
		int i,index=poss;
		for(i=poss+1;i<=m;i++)
		{
			if(mini>ig[i].c)
			{
				mini=ig[i].c;
				index=i;
			}
			if(mini==0)
				break;
		}
		temp=ig[index];
		ig[index]=ig[poss];
		ig[poss]=temp;
}

void process()
{
	int x;
	int cost=0;
	int node=n;
	int p=1;
	int p1,p2;
	int parent[2100]={0};
	while(k<node && p<=m)
	{
		pushup(p);
		p1=parent[ig[p].i];
		p2=parent[ig[p].j];
		if(p1!=0&&(p1==p2));	//skip
		else 				//process
		{
			if(p1==0&&p2==0)
			{	 parent[ig[p].i]=ig[p].i;  parent[ig[p].j]=ig[p].i;}
			else if(p1==0)
				parent[ig[p].i]=p2;
			else if(p2==0)
				parent[ig[p].j]=p1;
			else
			{
				for(x=1;x<=n;x++)
				{
					if(parent[x]==p2)
						parent[x]=p1;
				}
			}			
			cost+=ig[p].c;
			 node--;
		}
		p++;
	}

	if(k>=node)	
		printf("%d\n",cost);
	else
		printf("Impossible!\n");
}

