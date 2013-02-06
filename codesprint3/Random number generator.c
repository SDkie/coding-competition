#include<stdio.h>
int gcd ( int a, int b );
int temp;
int c,i,area,p, p2, p3,g;
    
int main()
{
	int t,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&x,&y,&c);
        if(x<y)
        {
            temp = x;x = y;y = temp;
        }
        if(i != 1)
			printf("\n");
        if(c <= (x>y?y:x))
        {
            area = c * c;
            g = gcd(area, x*y*2);
            printf("%d/%d",area/g,(x*y*2)/g);
        }
        else if(c >= x+y)
        {
            printf("1/1");
        }
        else if( c > (x>y?y:x) && c <= (x<y?y:x) )
        {
            p = c - y;
            area = ((c-p) * y) + (p * y * 2);
            g = gcd(area, x*y*2);
           printf("%d/%d",area/g,(x*y*2)/g);
        }
        else if( c < (x+y) && c >(x<y?y:x))
        {
            p = c - y;
            area = (y * p* 2);
            p2 = c - x;
            p3 = x - p;
            area = area + (p3 * p2 * 2) + ((y- p2) * p3);
            g = gcd(area, x*y*2);
            printf("%d/%d",area/g,(x*y*2)/g);
        }
    }
    return 0;
}

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

