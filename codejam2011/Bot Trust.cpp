#include<iostream>
using namespace std;
void read();
//unsigned long long int 4294967295 10000;
class robot
{
	unsigned long long int orange[65535],blue[65535];
	unsigned long long int sec;
	unsigned long long int o,b;
	unsigned long long int sequence[65535];
	unsigned long long int oposition,bposition;//button number
	unsigned long long int onext,bnext;//index
	unsigned long long int buttons;
	public:
	unsigned long long int ans[65535];
	public:
		void read();
		int calculate();
};
int main()
{
	unsigned long long int count,i;
	robot r;
     //	clrscr();
	cin>>count;
	for(i=0;i<count;i++)
	{
		r.read();
		
		r.ans[i]=r.calculate();
	}
	for(i=0;i<count;i++)
		cout<<"\nCase #"<<(i+1)<<": "<<r.ans[i];
	return 0;
}
int robot::calculate()
{

	unsigned long long int next;
	oposition=1;
	bposition=1;
	onext=0;bnext=0;
	sec=0;
	unsigned long long  int press;
//	cout<<"buttons"<<buttons;
	int binc,oinc;
	for(press=0;press<buttons;sec++)
	{
		if(oposition<orange[onext])
		{
			oinc=1;
		}
		else if(oposition>orange[onext])
			oinc=-1;
		else
			oinc=0;
		if(bposition<blue[bnext])
		{
			binc=1;
		}
		else if(bposition>blue[bnext])
			binc=-1;
		else
			binc=0;
	  /*	if(onext==o)
			oinc=0;
		if(bnext==b)
			binc=0;  */

  //		cout<<oinc<<":"<<binc<<"\t";
		if(sequence[press]>100)
			next=0;//ORANGE
		else
			next =1;//blue
		if(oposition!=orange[onext]&&bposition!=blue[bnext])
		{
    //			cout<<"o++ b++\n";
			oposition+=oinc;
			bposition+=binc;
		}
		else if(oposition!=orange[onext]&&bposition==blue[bnext])
		{
			if(next==1)
			{
      //				cout<<"b(press)";
				press++;
				bnext++;
			}

			oposition+=oinc;
		}
		else if(oposition==orange[onext]&&bposition!=blue[bnext])
		{
			if(next==0)
			{
  //				cout<<"o(press)";
				press++;
				onext++;
			}

			bposition+=binc;
		}
		else
		{
			if(next==0)
			{
				press++;
				onext++;
			}
			else
			{
				press++;
				bnext++;
			}
		}

	}
	return sec;
	}
void robot::read()
{
	unsigned long long int o=0,b=0,count,i;
	char choice;
	for(i=0;i<65535;i++)
	{
		orange[i]=0;
		blue[i]=0;
	}
	sec=0;
	oposition=0;
	bposition=0;
	onext=0;
	bnext=0;
	cin>>count;
	buttons=count;
	for(i=0;i<count;i++)
	{
		cin>>choice;
		if(choice=='O')
		{
			cin>>orange[o];
			o++;
			sequence[i]=100+orange[o-1];
		}
		else if(choice=='B')
		{
			cin>>blue[b];
			b++;
			sequence[i]=blue[b-1];
		}

	}
	orange[o]=orange[o-1];
	blue[b]=blue[b-1];
      //	orange[0]=o-1;
      //	blue[0]=b-1;

  /*
	{
	 for(i=0;i<o;i++)
		cout<<orange[i];
	 for(i=0;i<b;i++)
		cout<<blue[i];
		cout<<"\n";
	for(i=0;i<count;i++)
		cout<<sequence[i]<<":";

	} */

}
