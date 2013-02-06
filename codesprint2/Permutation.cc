#include<deque>
#include<iostream>
#define MAX 208
using namespace std;
long N[MAX*MAX]={0};
deque<int> a,b;
long n;
int position(int x,int y);
long sum(deque<int> d);
int main()
{
    long i=0,j=0,temp;
    cin>>n;
    int x,y;
    long inpt[MAX*MAX][2]={0,-1};   
    for(i=0;i<n*n;i++)
    {
      cin>>N[i];
      if(i/n!=i)
      {
        inpt[i][0]=N[i];
        inpt[i][1]=i;
       }
    }
   
    for(i=0;i<MAX;i++)
     {
        for(j=0;j<n*n;j++)
        {
                if(inpt[j][0]<inpt[j+1][0])
                {
                    temp=inpt[j][1];
                    inpt[j][1]=inpt[j+1][1];
                    inpt[j+1][1]=temp;
                    temp=inpt[j][0];
                    inpt[j][0]=inpt[j+1][0];
                    inpt[j+1][0]=temp;
                   
            }
        }
     }
     for(i=0;i<MAX;i++)
     {     
            x=inpt[i][1]/n;
            y=inpt[i][1]%n;
            a.push_front(x);
            a.push_back(y);
            for(j=0;j<n;j++)
            {   if(j!=x&&j!=y)
                {
                    if(N[position(j,x)]>N[position(y,j)])
                        a.push_front(j);
                    else
                        a.push_back(j); 
                }
            }
            if(b.empty())
                b=a;
            else
            {
                if(sum(a)>sum(b))
                    b=a;
            }
            a.clear();
		}       
        while(!b.empty())
        {cout<<b.front()<<" ";b.pop_front();}
    return 0;
}

int position(int x,int y)
{
    return x*n+y;
}
long sum(deque<int> d)
{   long s=0;
    int ix=0,iy=0;
    deque<int> temp;
    temp=a;
    if(!temp.empty())
    {
        ix=temp.front();
        temp.pop_front();
        while(!temp.empty())
        {  
            iy=temp.front();
            temp.pop_front();
            s+=N[ix*n+iy];
            ix=iy;
        }
    }
    return s;
}

