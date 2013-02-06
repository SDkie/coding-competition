#include<iostream>
#include<string.h>
#define SIZE 11
using namespace std;
class str
{
	public:
	int endinput;
	int endoutput;
	int endcom;
	int endopp;
	char input[SIZE];
	char output[SIZE];
	char combine[SIZE][4];
	char opposed[SIZE][3];
	char buff[2];
	char final[100][SIZE];
	public:
			void read();
			void cal(int i);
};
int main()
{
	int count;
	int i;
	str var;
	cin>>count;
	for(i=0;i<count;i++)
	{
		var.read();
		cout<<"\n"<<var.input;
		var.cal(i);
	}
	int j;
	for(i=0;i<count;i++)
	{
		cout<<"\nCase #"<<(i+1)<<": [";
		for(j=0;var.final[i][j]!='\0';j++)
		{
			cout<<var.final[i][j]<<", ";
		}
		if(j!=0)
		cout<<"\b\b";
		cout<<"]";
	}
}
void str::cal(int position)
{
	int i;
	int in=0,out=0;
	while(in<endinput)
	{
		output[out]=input[in];
	if(out>=1)
	{
		for(i=0;i<endcom;i++)
		{
							if((output[out]==combine[i][0]&&output[out-1]==combine[i][1]) || (output[out]==combine[i][1]&&output[out-1]==combine[i][0]))
							{	
								out--;
								output[out]=combine[i][2];
								i=0;
								//cout<<"check\t"<<out<<output[out];
							}
		}
	}
	if(out>=1)
	{
		int j;
		for(i=0;i<endopp;i++)
		{
			if(output[out]==opposed[i][0])
			{
				for(j=0;j<=out-1;j++)
				{
					if(output[j]==opposed[i][1])
					{
						out=-1;
					//	cout<<"del\n";
						goto end;
					}
				}
			}
			else if(output[out]==opposed[i][1])
			{
				for(j=0;j<=out-1;j++)
				{
					if(output[j]==opposed[i][0])
					{
						out=-1;
					//	cout<<"del\n";
						goto end;
					}
				}
			}
			
		}
	}
		end:
		out++;//garbage 
		in++;
		
	}
	output[out]='\0';
	//cout<<out<<":";
	strcpy(final[position],output);
}
void str::read()
{
	cin>>endcom;
	int i;
	for(i=0;i<endcom;i++)
	{
		cin>>combine[i];
	}
	cin>>endopp;
	for(i=0;i<endopp;i++)
	{
		cin>>opposed[i];
	}
	cin>>endinput;
	cin>>input;
}
