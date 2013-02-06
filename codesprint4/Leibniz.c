/*
In Calculus, the Leibniz formula for π is given by:
or:

You will be given an integer ‘n’. Your task is to print the summation of the Leibniz formula up to the nth term of the series correct to 15 decimal places.

Input Format

The first line contains an integer T (<=100). T testcases follow. Each testcase has a single line with a positive integer n (< 10^7).

Sample Input

2
10
20

Output Format

Output T lines, with each line containing the summation up to nth term.

Sample Output

0.760459904732351
0.772905951666960

Scoring

This is a code golf question, the goal is to write a solution with as little code as possible. A correct submission with a source code of X characters will receive the following score:

30 - X/10

Any correct code longer than 300 characters will receive a score of 0.03.
*/

main(){int n,i,t;scanf("%d",&t);while(t--){double o=0;scanf("%d",&n);for(i=0;i<n;i++) o+=(i%2?-1:1)/(2.0*i+1);printf("%.15lf\n",o);}}
