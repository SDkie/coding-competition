'''
Problem: https://www.hackerrank.com/contests/codesprint5/challenges/hyperrectangle-gcd

Let there be a K-dimensional Hyperrectangle, where each dimension has a length of n1,n2,…nk.
Each of the Hyperrectangle’s unit cells is addressed at (i,j,k,…) and has a value which is equivalent to GCD(i,j,k,…) where 1 <= i <= n1 , 1 <= j <= n2 ….

The goal is to sum all the GCD(i,j,k,…) cell values and print the result modulo 10^9 + 7. Note that indexing is from 1 to N and not 0 to N-1.

Input Format 
The first line contains an integer T. T testcases follow.
Each testcase contains 2 lines, the first line being K (K-dimension) and the second line contains K space separated integers indicating the size of each dimension - n1 n2 n3 … nk

Output Format 
Print the sum of all the hyperrectangle cell’s GCD values modulo 10^9 + 7 in each line corresponding to each test case.

Constraints
1 <= T <= 1000
2 <= K <= 500
1 <= nk <= 100000

Sample Input #00

2
2
4 4
2
3 3
Sample Output #00

24
12
Sample Input #01

1
3
3 3 3
Sample Output #01

30
Explanation #00 
For the first test case, it’s a 4X4 2-dimension Rectangle. The (i,j) address and GCD values of each element at (i,j) will look like

1,1 1,2 1,3 1,4              1 1 1 1  
2,1 2,2 2,3 2,4  => GCD(i,j) 1 2 1 2  
3,1 3,2 3,3 3,4              1 1 3 1  
4,1 4,2 4,3 4,4              1 2 1 4  
Sum of these values is 24

Explanation #00
Similarly for 3X3 GCD (i,j) would look like

1,1 1,2 1,3               1 1 1  
2,1 2,2 2,3  => GCD(i,j)  1 2 1  
3,1 3,2 3,3               1 1 3  
Sum is 12

Explanation #01 
Here we have a 3-dimensional 3X3X3 Hyperrectangle or a cube. We can write it’s GCD (i,j,k) values in 3 layers.

1,1,1 1,1,2 1,1,3  |  2,1,1 2,1,2 2,1,3  |  3,1,1 3,1,2 3,1,3  
1,2,1 1,2,2 1,2,3  |  2,2,1 2,2,2 2,2,3  |  3,2,1 3,2,2 3,2,3  
1,3,1 1,3,2 1,3,3  |  2,3,1 2,3,2 2,3,3  |  3,3,1 3,3,2 3,3,3  
GCD (i,j,k)
1 1 1              |  1 1 1              |  1 1 1  
1 1 1              |  1 2 1              |  1 1 1  
1 1 1              |  1 1 1              |  1 1 3  

'''

def generateFact(UL):
    Fact = [[1] for i in xrange(UL)]
    maxlook= int(UL / 2) + 1
    #Adding fact to respective numbers
    for i in xrange(2, maxlook):
        step = i
        for j in xrange(i, UL, step):
            Fact[j].append(i)
    return Fact


UL = 100000
Fact = generateFact(UL)
Testcases = int(raw_input())
for t in xrange(Testcases):
    k = int(raw_input())
    d = [int(m) for m in raw_input().split(" ")]
    d1=[1]*len(d)
    l = len(d1)-1
    sum = 0
    j = 2
    while True:
        if min(d1)==1:
            sum=sum+1
        else:
            factList = []
            for i in set(d1):
                factList.append(Fact[i])
            sum+= max(set(factList[0]).intersection(*factList))
        if d1[l]==d[l]:
            d1[l]=1
            m = l-1
            while True:
                if m<0:
                    break
                if d[m]==d1[m]:
                    d1[m]=1
                    m=m-1
                else:
                    d1[m]=d1[m]+1
                    break
            if m<0:
                break
        else:
            d1[l]=1+d1[l]
    print sum
