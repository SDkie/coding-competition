"""
In Calculus, the Leibniz formula for PI is given by:
You will be given an integer n. Your task is to print the summation of the Leibniz formula up to the nth term of the series correct to 15 decimal places.

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
"""
for n in range(input()):
 a=0
 for i in range(input()):
  a+=(1,-1)[i%2]/(2.*i+1)
 print'%.15f'%a
