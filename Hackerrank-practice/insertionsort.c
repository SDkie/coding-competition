#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/* Head ends here */
void insertionSort(int ar_size, int *  ar) {

	int i,j,temp,n=ar_size,p;
	for(i=0;i<n-1;i++)
	{
		temp=ar[i+1];
		for(j=i;j>=0;j--)
		{
			if(ar[j]>temp)
			{
				ar[j+1]=ar[j];
			}
			else
				break;
		}
			
			ar[j+1]=temp;
			for(p=0;p<n;p++)
				printf("%d ",ar[p]);
			printf("\n");
	}
}

/* Tail starts here */
int main() {
   
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   		scanf("%d", &_ar[_ar_i]); 
	}
insertionSort(_ar_size, _ar);
   return 0;
}
