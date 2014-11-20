#include<stdio.h>
#include<string.h>

char str[10010];

int main()
{
	int t;
	int i;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%s",&str);
		print_out();
	}
}

print_out()
{
	int len;
	len = strlen(str);
	int ptr=0;
	int ret;
	while(ptr < len)
	{
		if(ptr!=0)
			printf(",");
		ret = rule1(ptr);
		if(ret>1)
		{
			printf("%c*%d",str[ptr],ret);
			ptr+=ret;
			continue;
		}
		
		ret = rule2(ptr);
		if(ret>1)
		{
			printf("%c-%c",str[ptr],str[ptr+ret-1]);
			ptr+=ret;
			continue;
		}
		printf("%c",str[ptr++]);
	}
	printf("\n");
}
int rule1(int ptr)
{
	int count=1;
	int ch = str[ptr];
	ptr++;
	while(str[ptr++] == ch)
		count++;
	
	return count;
}

int rule2(int ptr)
{
	int ch = str[ptr];
	int count=1;
	ptr++;
	ch++;
	while(str[ptr++] == ch++)
	{
		if(rule1(ptr-1)>1)
			return count;
		count++;
	}
	return count;
}

