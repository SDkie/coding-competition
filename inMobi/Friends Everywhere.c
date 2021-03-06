/*4.Friends Everywhere [200 points] [http://www.hackerearth.com/inmobi-hiring-challenge/approximate/friends-everywhere/]
In Futaba Kindergarten, where Shinchan studies, there are N students, s_0, s_1...s_(N-1), including Shinchan. Every student knows each other directly or indirectly. Two students knows each other directly if they are friends. Indirectly knowing each other means there is a third students who knows both of them. Knowing each other is a symmetric relation, i.e., if student s_a knows student s_b then student s_b also knows student s_a.

Ai-chan is a new admission in the class. She wants to be friend with all of them. But it will be very cumbersome to befriend each of the N students there. So she decided to befriend some of them such that every student in the class is either a friend of her or friend of friend of her.

Help her to select those students such that befriending them will complete her objective. The lesser number of students the better it is.

Input

First line of input will contain two space separated integer, N M, number of students at Futaba Kindergarten, excluding Ai-chan, and number of pairs of students who are friend to each other, i.e. they knows each other directly. Then follows M lines. In each line there are two space separated integer, s_u s_v, such that student s_u and s_v are friend to each other.

Output

In first line print the total number, P, of such students. Then in next line print P space separated index of students, such that befriending them will help Ai-chan to achieve her objective.

Constraints

1 <= N <= 10^5

1 <= M <= min(10^5, N*(N-1)/2)

0 <= s_u, s_v <= N-1

s_u != s_v

Each pair of students (s_u, s_v) knows each other, directly or indirectly.

Score: ((N-P)/N)*200

Sample Input
6 7
0 1
0 2
1 2
1 3
2 4
3 4
3 5

Sample Output
4
0 2 3 5

Explanation

Test Case #1: Students (s_0, s_2, s_3, s_5) are to be befriended. s_1 is a friend of s_0 and s_4 is a friend of s_3. So (s_1, s_4) are friends of friends.
Score = (6-4)/6*200 = 66.67

Time limit 5 sec(s)

Memory limit 256 MB

Source limit 1024 KB*/


#include<stdio.h>
#include<malloc.h>
#define MAX 100010

int add(int p,int q);
void print();


struct linklist{
	int data;
	struct linklist* next;
}friend[MAX];

struct linklist* last[MAX];

int degree[MAX]={0};
int solution[MAX];
int solutionptr=0;
int n,m;

int main()
{
	int i,j;
	int p,q;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&p,&q);
		add(p,q);
		degree[p]++;
		degree[q]++;
	}	
		
	calculate();
	printf("%d\n",solutionptr);
	
	for(i=0;i<solutionptr;i++)
	{
		printf("%d ",solution[i]);
	}
	return 0;
}

int calculate()
{
	int mini_pos;
	int max_degree=0;
	int max_pos;
	int temp;
	struct linklist* node;
	while(1)
	{
		mini_pos=minimum();
		if(mini_pos==-1)
			break;
		max_degree=0;
		node=friend[mini_pos].next;

		/*while(node!=NULL)
		{
			temp=degree[node->data];
			if(max_degree<temp&&temp!=n)
			{
				max_degree=temp;
				max_pos=node->data;
			}
			node=node->next;					
		}*/
	
		max_pos=node->data;		
		
		solution[solutionptr++]=max_pos;	
		degree[max_pos]=n;
		node=friend[max_pos].next;

		
		while(node!=NULL)
		{
			degree[node->data]=n;
			node=node->next;					
		}
					
	}
}

int minimum()
{
	int mini=n;	
	int pos,i;
	for(i=0;i<n;i++)
	{
		if(mini>degree[i])
		{
			pos=i;
			mini=degree[i];
			break;
		}	
	}	
	return (mini==n?-1:pos);
}


int add(int p,int q)
{
	struct linklist* node;
	
	if(last[p]==NULL)
	{
		friend[p].next=malloc(sizeof(struct linklist));
		last[p]=friend[p].next;
		last[p]->data=q;
	}
	else
	{
		last[p]->next=malloc(sizeof(struct linklist));
		last[p]=last[p]->next;
		last[p]->data=q;
	}


	if(last[q]==NULL)
	{
		friend[q].next=malloc(sizeof(struct linklist));
		last[q]=friend[q].next;
		last[q]->data=p;
	}
	else
	{
		last[q]->next=malloc(sizeof(struct linklist));
		last[q]=last[q]->next;
		last[q]->data=p;
	}

}
