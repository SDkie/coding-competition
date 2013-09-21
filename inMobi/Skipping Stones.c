/*3. Skipping Stones [150 points] [http://www.hackerearth.com/inmobi-hiring-challenge/algorithm/skipping-stones/]
My flatmate, Sayan, went to the game show called Takeshi's castle.It is a game show in which you need to pass different game challenges to enter the final.

Now the most famous round of all of them is the "skipping stones".In the game you need to go from one end of a small puddle to the other end of it stepping on stones.Some of the stones are fixed while others sink as soon as you step on them.

Now Sayan managd to bribe the gaurd and gather the information regarding each of the stones in the puddle. So he now knows the probability p of each stone staying stationary, i.e, the probability of stepping on a stone and not sinking is p.

Now , as common sense suggests, Sayan can cross the puddle only if he steps on stationary stones only.

But Sayan, being a human being, has a fixed span of distance(L) which he can jump at once.You need to find out and inform Sayan the best probability of him crossing the puddle without sinking.

NOTE: He can jump from one stone to another only if it is within L metres of distance.

INPUT:

The first line of input contains three numbers n, L and D , the number of stones in the puddle, the span of Sayan's jump, and length of the puddle respectively. The next line contains n space separated floating point numbers, with ith number denoting the probability p of the ith stone being stationary.(1<=i<=n). The next line contains the distance d of the stones from the starting point in serial order, i.e, from 1 to n.

OUTPUT:

Print one floating point number containing the answer of the problem exact to 6 decimals. if no such answer is possible print "IMPOSSIBLE" without the quotes.

CONSTRAINTS:

0.0 <= p <= 1.0

1 <= n <= 1000

1 <= d <= D <= 10000

1 <= L <= 10000

Sample Input
5 3 10
0.5 0.4 0.6 0.8 1.0
2 3 5 6 8

Sample Output
0.320000

Explanation

The best jump will be to jump from start to 2nd stone(with p=0.4), them to 4th stone(with p=0.8), then to 5th stone(with p=1.0) and finally to the end of the puddle.

Time limit 3 sec(s)

Memory limit 256 MB

Source limit 1024 KB
*/



#include<stdio.h>
#define MAX 1005

int n,l,d,count;
int i,j;

float cal(int current);
float prob[MAX];
int dist[MAX];
float Rprob[MAX]={0};
float cal(int current)
{
	float result=0.0,new;
	int k=current+1;
	while(1)
	{
		if(k==n)
		{
			result=1.0;
			break;
		}
		else if(l>=dist[k]-dist[current])
		{
			new=Rprob[k]*prob[k];
			if(result<new)
				result=new;
			k=k+1;
		}	
		else
			break;
	}
	//printf("%d:%f\n",current,result);
	return result;
}

int main()
{
	int current,scan;
	float final;
	scanf("%d %d %d",&n,&l,&d);
	for(i=0;i<n;i++)
		scanf("%f",&prob[i]);
	for(i=0;i<n;i++)
		scanf("%d",&dist[i]);

	prob[n]=1;
	dist[n]=d;
	n++;
	current=-1;	
	for(scan=n;scan>0;scan--)
		Rprob[scan]=cal(scan);		
	final=cal(-1);
	if(final==0)
		printf("IMPOSSIBLE");
	else
		printf("%f",final);
}
