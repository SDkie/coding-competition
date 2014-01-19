/*
Problem: https://www.hackerrank.com/contests/codesprint5/challenges/special-multiple

You are given an integer N. Can you find the least positive integer X made up of only 9’s and 0’s such that X is a multiple of N?

Update

X is made up of one or more occurences of 9 and zero or more occurences of 0.

Input Format
The first line contains an integer T which denotes the number of test cases. T lines follow.
Each line contains the integer N for which the solution has to be found.

Output Format
Print the answer X to STDOUT corresponding to each test case. The output should not contain any leading zeroes.

Constraints
1 <= T <= 104
1 <= N <= 500

Sample Input

3
5
7
1
Sample Output

90
9009
9
Explanation
90 is the smallest number made up of 9’s and 0’s divisible by 5. You can derive similarly for other cases.
*/


#include<stdio.h>
#include<math.h>

long long series[1000000]={9,90,99,900,0};
long long i=0;
long long j=3;
long long k=3;
void gen(long long);
long long find(long double);

int main()
{
	long long t,p;
	int no;
	long long res = 0;
	scanf("%lld",&t);
	
	for(p=0;p<t;p++)
	{
		scanf("%d",&no);	
		res=find((long double)no); 
		printf("%lld : %lld %llf	\n",res , series[res], series[res]/(long double)no);	
	}
}

long long find(long double no)
{
	long long x=0;
	for(;;)
	{
		gen(x);
		if( (series[x]/no - floor(series[x]/no)) == 0)
			return x;
		else
			x++;	
	}	
}

void gen(long long x)
{
	if(x>k)
	{
		if(i==j)
		{
			series[++k]=series[j]*10;
			j=k;
			i=0;
		}
		else
			series[++k]=series[j]+series[i++];
	}
	printf("%lld\n",series[k]);
}
