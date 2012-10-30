n=input();
for k in range(0,n):
	cities=input();
	people=[0]*cities; 
	distance=[0]*cities;
	i=0;
	for inp in raw_input().split():
		distance[i]=int(inp);
		i=i+1;
	i=0;
	for inp in raw_input().split():
		people[i]=int(inp);
		i=i+1;
	dist=0;
	for i in range(0,cities-1):
		for j in range(i+1,cities):	
				dist=(dist+((people[i] if people[i]>people[j] else people[j])*abs(distance[j]-distance[i])))%1000000007;
	print dist;

