import java.io.*;
import java.lang.StringBuilder; 
class cust
{
	int oid;	//    Order id (numeric)
	int did;//    Deal id (numeric)
	StringBuilder email;//   Email address
	StringBuilder address;//   Street address
	StringBuilder city; //  City
	StringBuilder State;//  State
	StringBuilder zipcode;		//  Zip Code
	long creditcard;		//   Credit Card 
}
public class Solution{

	public static void main(String[] args) throws IOException {
		int testcases;
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int i,j;
	    testcases=Integer.parseInt(br.readLine());
	    
	    cust arr[]=new cust[testcases];
	    int from=0;
	    int to;
	    i=0;
	    int temp;
	   for(i=0;i<testcases;i++)
	    {
	    	arr[i]=new cust();
	    	StringBuilder input=new StringBuilder(br.readLine());
	    	from=0;
	    	to=input.indexOf(",",from);
	    	arr[i].oid=Integer.parseInt(input.substring(from,to));
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].did=Integer.parseInt(input.substring(from,to));
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].email=new StringBuilder(input.substring(from,to).toLowerCase());
	    	temp=arr[i].email.indexOf("+");
	    	if(temp!=-1)
	    	{
	    		arr[i].email.delete(temp,arr[i].email.indexOf("@"));
	    	}
	    	while(arr[i].email.indexOf(".")!=-1)
	    	{
	    		arr[i].email.deleteCharAt(arr[i].email.indexOf("."));
	    	}
	    	while(arr[i].email.indexOf(" ")!=-1)
	    	{
	    		arr[i].email.deleteCharAt(arr[i].email.indexOf(" "));
	    	}
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].address=new StringBuilder(input.substring(from,to).toLowerCase());
	    	temp=arr[i].address.indexOf("street");
	    	if(temp!=-1)
	    	{
	    		arr[i].address.replace(temp, temp+6, "st.");
	    	}
	    	while(arr[i].address.indexOf(" ")!=-1)
	    	{
	    		arr[i].address.deleteCharAt(arr[i].address.indexOf(" "));
	    	}
	    	
	    	temp=arr[i].address.indexOf("road");
	    	if(temp!=-1)
	    	{
	    		arr[i].address.replace(temp, temp+4, "rd.");
	    	}
	    	
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].city=new StringBuilder(input.substring(from,to).toLowerCase());
	
	    	while(arr[i].city.indexOf(" ")!=-1)
	    	{
	    		arr[i].city.deleteCharAt(arr[i].city.indexOf(" "));
	    	}
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].State=new StringBuilder(input.substring(from,to).toLowerCase());
	    	
	    	temp=arr[i].State.indexOf("illinois");
	    	if(temp!=-1)
	    		arr[i].State.replace(temp, temp+8, "il");
	    	
	    	temp=arr[i].State.indexOf("california");
	    	if(temp!=-1)
	    		arr[i].State.replace(temp, temp+10, "ca");
	    	
	    	temp=arr[i].State.indexOf("new york");
	    	if(temp!=-1)
	    		arr[i].State.replace(temp, temp+8, "ny");
	    	
	    	while(arr[i].State.indexOf(" ")!=-1)
	    	{
	    		arr[i].State.deleteCharAt(arr[i].State.indexOf("."));
	    	}
	    	from=to+1;
	    	to=input.indexOf(",",from);
	    	arr[i].zipcode=new StringBuilder(input.substring(from,to));
	    	
	    	from=to+1;
	    	arr[i].creditcard=Long.parseLong(input.substring(from,input.length()));
	    	
	    	//System.out.print(arr[i].address+":"+arr[i].State);
	  	//System.out.println("\n"+arr[i].oid+""+arr[i].did+arr[i].email+arr[i].address+arr[i].city+"("+arr[i].State+arr[i].zipcode+")"+arr[i].creditcard);
	    	//System.out.print(arr[i].oid+""+arr[i].did);
	    }
	   int[] result=new int[testcases*1947];
	   int count=0;
	   for(i=0;i<testcases-1;i++)
	   {
		   for(j=i+1;j<testcases;j++)
		   {
			   //if(((arr[i].email.toString().equals(arr[j].email.toString()))&&(arr[i].did==arr[j].did)&&(arr[i].creditcard!=arr[j].creditcard))||(((arr[i].address.toString().equals(arr[j].address.toString()))||(arr[i].city.toString().equals(arr[j].city.toString()))||(arr[i].State.toString().equals(arr[j].State.toString()))||(arr[i].zipcode.toString().equals(arr[j].zipcode.toString())))&&(arr[i].did==arr[j].did)&&(arr[i].creditcard!=arr[j].creditcard)))
			   if(arr[i].did==arr[j].did&&arr[i].creditcard!=arr[j].creditcard)
			   {
				   			if(arr[i].email.toString().equals(arr[j].email.toString()))
						   {
					   			result[count++]=arr[i].oid;
					   			result[count++]=arr[j].oid;
						   }
				   			else if((arr[i].address.toString().equals(arr[j].address.toString()))||(arr[i].city.toString().equals(arr[j].city.toString()))||(arr[i].State.toString().equals(arr[j].State.toString()))||(arr[i].zipcode.toString().equals(arr[j].zipcode.toString())))
				   					{
					   			result[count++]=arr[i].oid;
					   			result[count++]=arr[j].oid;		
				   	}
			   }
		   }
	   }
	   if(count==0)
		   return;
	   int temp1=0;
	   for(i=0;i<count-1;i++)
	   {
		   for(j=i+1;j<count;j++)
		   {
			   if(result[i]>result[j])
			   {
				   temp1=result[i];
				   result[i]=result[j];
				   result[j]=temp1;
			   }
		   }
	   }
	   int a,b;
	   System.out.print(result[0]);
	   a=result[0];
	   for(i=1;i<count;i++)
	   {
		   if(a==result[i])
		   {
			   continue;
		   }
		   System.out.print(","+result[i]);
		   a=result[i];
	   }
	   }
}


