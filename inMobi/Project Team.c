/*1. Project Team [50 points] [http://www.hackerearth.com/inmobi-hiring-challenge/algorithm/project-team/]
A Professor of Physics gave projects to the students of his class. The students have to form a team of two for doing the project. The professor left the students to decide the teams. The number of students in a class will be even.

Each student has a knowledge level. It tells how much knowledge each student has. The knowledge level of a team is the sum of the knowledge levels of both the students.

The students decide to form groups such that the difference between the team with highest knowledge and the one with lowest knowledge is minimum.

Input

First line of the input will contain number of test cases t; In the next t lines the first number is n the number of students in the class followed by n integers denoting the knowledge levels of the n students

Output

Your output should be a single line containing the lowest possible difference between the team with highest knowledge and the one with lowest knowledge.

Sample Input
2
4 2 6 4 3
6 1 1 1 1 1 1

Sample Output
1
0

Explanation

Input Constraints are

1 <= t <= 100
1 <= n <= 100
1 <= knowledge level <= 10000

Time limit 1 sec(s)

Memory limit 256 MB

Source limit 1024 KB*/


#include<stdio.h>
#define MAX 100
void partition(int a[MAX],int low,int high);
void merge(int a[MAX],int l,int m,int h);
void print(int a[MAX],int size);
int main()
{
	int t;
	int i,j,p,q,count,k;
	int min,max,diff;
	int input[MAX];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&count);
		for(j=0;j<count;j++)
			scanf("%d",&input[j]);
		partition(input,0,count-1);
		min=input[0]+input[count-1];
		max=min;
		for(k=1;k<count/2;k++)
		{
			diff=input[k]+input[count-1-k];
			if(max<diff)
				max=diff;
			if(min>diff)
				min=diff;
		}
		printf("%d\n",max-min);
	}
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

void print(int a[MAX],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\t",a[i]);
	
	printf("\n");
}
