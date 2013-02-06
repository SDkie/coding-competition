#include<stdio.h>
#define MAX 999

int k;
int num[MAX];//max 101
int mat[MAX][MAX];
int parent[MAX];
int mini=200;
int indexmini;
int main()
{
	int p,q,r,s;
	char t;
	int father;
	scanf("%d",&k);
	for(p=0;p<k;p++)
	{	
		scanf("%d",&num[p]);
	}
	
	for(p=0;p<k;p++)
	{
		scanf("%c",&t);	
		for(q=0;q<k;q++)
		{
			scanf("%c",&t);
			mat[p][q]=((t=='Y')?num[p]:MAX);
			if(p==q)
				mat[p][q]=num[p];
		}
		parent[p]=p;
	}
	
	for(p=0;p<k;p++)
	{
		father=parent[p];
		for(q=p+1;q<k;q++) 			//compare each q with p only 1s
		{
				if(parent[q]==q)	//moved elseware
				{
					for(r=0;r<k;r++) //compare
					{
						if(mat[r][father]==mat[r][q]&&mat[r][father]!=MAX)//same
						{
							for(s=0;s<k;s++)//copy
							{
								if(mat[s][q]!=MAX)
									mat[s][father]=mat[s][q];
							}
							parent[q]=father;
							r=k;
						}
					}
				}
		}
	}
	
	


	for(p=0;p<k;p++)
	{
		father=parent[p];
		mini=MAX;
		for(q=0;q<k;q++)
		{
			if(mini>mat[q][father])
			{
				mini=mat[q][father];
				indexmini=q;
			}
		}
		mat[indexmini][father]=MAX;
		if(q==k-1)
			printf("%d",mini);
		else
			printf("%d ",mini);
	}	
	return 0;
}

