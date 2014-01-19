/*
Problem: https://www.hackerrank.com/contests/codesprint5/challenges/matrix-tracing

Given below is a word from the English dictionary arranged as a matrix

MATHE
ATHEM
THEMA
HEMAT
EMATI
MATIC
ATICS

Tracing the matrix is starting from the top left position and at each step move either RIGHT or DOWN, to reach the bottom right of the matrix. It is assured that any such tracing generates the same word. How many such tracings can be possible for a given word of length m+n-1 written as a matrix of size m * n?

Input Format
The first line of input contains an integer T. T test cases follow in each line.
Each line contains 2 space separated integers m & n indicating that the matrix written has m rows and each row has n characters.

Constraints
1 <= T <= 103
1 ≤ m,n ≤ 106

Output Format
Print the number of ways (S) the word can be traced as explained in the problem statement. If the number is larger than 109+7, 
print S mod (10^9 + 7) for each testcase in a newline.

Sample Input

1
2 3
Sample Output

3
Explanation
Let us consider a word AWAY written as the matrix

AWA
WAY
Here, the word AWAY in the matrix can be traced in 3 different ways, traversing either RIGHT or DOWN.

AWA
  Y

AW
 AY

A
WAY
Hence the answer 3.
*/

#include<stdio.h>
#include<math.h>
#define MOD 1000000007L


long long generate(long long m,long long n)
{
	long long i;
	long double result=m;

	if(m==1 || n==0)
		return 1;	

	for(i=1;i<n;i++)
	{
		result = (result)*((((long double)m+i)/(i+1))); 
		result = (roundl(result));
	}
	
    return ((long long)roundl(fmodl(result,MOD)));
}		

		
int main()
{
	long long i;
	long long t;			//1 <= T <= 103
	long long m,n;		//1 ? m,n ? 106

	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
			scanf("%lld %lld",&m,&n);	
			printf("%lld\n",generate(m,n-1));
	}
}
