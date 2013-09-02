import java.io.*;
import java.util.*;

public class hackercup {
	public static void main (String[] args) throws IOException
	{
	
		int newValue,tempValue;
		String inputString; // take input line in this, convert into byte array and then readAlphabet
		//char data;
		
		// in loop of reading alphabet
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		//System.out.print(n-48);
		
		for(int k=1;k<=n;k++)
		{
			HashMap <Character,Integer> count=new HashMap<Character, Integer>();
			inputString=br.readLine();
			//System.out.println(inputString);
			
			char[] data = inputString.toCharArray();
					
			for(int i=0;i<data.length;i++)
			{
				if(count.containsKey(data[i]))
				{
				//	System.out.println("in if1");
					tempValue=count.get(data[i]);
					newValue=tempValue+1;
					count.put(data[i], newValue);
				}
				else
				{
					//System.out.println("in else1");
					count.put(data[i], 1);
				}
			
			}
			
			/*Iterator iterator = count.keySet().iterator();  
		    
			
		    while (iterator.hasNext())
		    {  
		       Character key1 = (Character) iterator.next(); //d3 key1 and value1 are just for printing the hashmap  
		       int value1 = count.get(key1);  
		       
		       System.out.println(key1 + " " + value1);  
		    }*/
										
			int[] ans=new int[8];
			/*for(int i=0;i<8;i++)
				ans[i]=0;*/
			//int h=0,a=0,c=0,k=0,e=0,r=0,u=0,p=0; // c is two times!!
			
			if(count.containsKey('H'))
				ans[0]=count.get('H');
			if(count.containsKey('A'))
				ans[1]=count.get('A');
			if(count.containsKey('C'))
				ans[2]=count.get('C')/2;
			if(count.containsKey('K'))
				ans[3]=count.get('K');
			if(count.containsKey('E'))
				ans[4]=count.get('E');
			if(count.containsKey('R'))
				ans[5]=count.get('R');
			if(count.containsKey('U'))
				ans[6]=count.get('U');
			if(count.containsKey('P'))
				ans[7]=count.get('P');
			
			//System.out.print(h);
			/*for(int j=0;j<8;j++)
			{
				System.out.println(ans[j]);
			}*/
			java.util.Arrays.sort(ans);
			System.out.println("Case #"+k+": "+ans[0]);
		}
	}


}
