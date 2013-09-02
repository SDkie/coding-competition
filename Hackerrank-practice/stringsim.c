#include<stdio.h>
#include<string.h>

int similar(char* a, char* b)
{       
        int size=strlen(a);
        int count=0;
        int i;
        for(i=0;i<size;i++)
        {
                if((a[i]==b[i])!='\0')
                        count++;
                else
                {
                        printf("%s %s %d\n",a,b,count);    
                        return(count);
                }
        }
    
}

int main()
{
        int tt,size;
        int i,j,k,count;
        char input[100000];

        scanf("%d",&tt);
        for(i=0;i<tt;i++)
        {
                count=0;
                scanf("%s",input);
                size=strlen(input);
                for(j=0;j<size;j++)
                        count+=similar(input,&input[j]);
                printf("%d\n",count);
        }               
        return 0;

}

