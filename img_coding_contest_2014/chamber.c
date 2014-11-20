#include<stdio.h>
#include<math.h>

int find_low_prime(int p);
int find_high_prime(int p);
int isprime(int p);

int main()
{
	int t;
	int a;
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d", &a);
		printf("%ld\n",find_low_prime(a) +  find_high_prime(a));
	}
	
}

int find_low_prime(int p)
{
	while(!isprime(--p));
//	printf(" low: %d\n", p);
	return p;
}

int find_high_prime(int p)
{
	while(!isprime(++p));
//	printf("high: %d\n", p);
	return p;
}

int isprime(int p)
{
        if (p < 2) return 0;
        if (p % 2 == 0) return (p == 2);
        int i;
        for (i = 3; i < p; i += 2)
        {
            if (p % i == 0) return 0;
        }
        return 1;
}
