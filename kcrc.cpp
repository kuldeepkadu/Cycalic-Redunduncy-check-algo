#include<iostream>
using namespace std;
 
 int main()
 {
	 string msg,msg1,crc,crc1,encoded="",encoded1;
	 cout<<"\t\tEnter MESSAGE : ";
	 getline(cin,msg);
	 
	 cout<<"\t\tENTER crc generator polynomial : ";
	 getline(cin,crc);
	 
	 int m = msg.length();
	 int n = crc.length();
	 
	 cout<< "FOR SERNDER'S SIDE----- ";
	 encoded = encoded + msg;
	 for(int i = 1 ; i<= n-1; i++)
		 encoded = encoded + '0';
	 for(int i=0; i<=encoded.length()-n;)
	 {
		 for(int j=0;j<n;j++)
			 encoded[i+j] = encoded[i+j] == crc[j] ? '0':'1';
			for(;i<encoded.length() && encoded[i]!= '1' ; i++)
			{
			}
	 }
	 cout<<"\n\tMASSAGE SEND : "<<msg;
	 cout<<"\n\tREMINDER : "<<encoded.substr(encoded.length()-n+1);
	 cout<<"\n\tFINAL MSG IS : "<<msg + encoded.substr(encoded.length()-n+1);
	 cout<< "\nFOR RECEIVER'S SIDE---------";
	 cout<<"\n\tEnter Receiver's Data : " ;
	 getline(cin,encoded1);
	 cout<<"\n\tEnter Crc generator Polynomial : ";
	 getline(cin,crc1);
	 
	 
	 for(int i=0; i<=encoded1.length()-crc1.length();)
	 {
		  
		 for(int j=0;j<crc1.length();j++)
			 encoded1[i+j] = encoded1[i+j] == crc1[j] ? '0':'1';
			for(;i<encoded1.length() && encoded1[i]!= '1' ; i++)
			{
			}
	 }
	 cout<<"\n\tREMINDER : "<<encoded1.substr(encoded1.length()-n+1);
	 
	 
	 for(int i=0;i<encoded1.length();i++)
	 {
		 if(encoded1[i]!='0')
		 {
			 cout<<"\n\tERROR CHECK : ERROR In Communication ";
			 return 0;
		 }
	 }
	 
	 cout<<"\n\tERROR CHECK : NO ERROR !";
	 
	 
	  return 0;
 }
 
