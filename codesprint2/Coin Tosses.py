import math;
testcases=input();
for i in range(0,testcases):
	inp=raw_input().split();
	n1=int(inp[0]);
	n2=int(inp[1]);
	print str(pow(2,n2+1)*(pow(2,n1-n2)-1))+'.00';
