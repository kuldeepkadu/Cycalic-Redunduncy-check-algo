#include <stdio.h>
 //#include <conio.h>
//#include <ncurses.h>
 #include <string.h>
 void main() 
{
	int i,j,keylen,msglen;
	char input[100], key[30],temp[30],quot[100],rem[30],key1[30];
	//clrscr();
	printf("Enter Data: ");
	scanf("%c", &input);
	//gets(input);

	//printf("Enter Key: ");
	//scanf("%c", &key);
	//gets(key);
	
	keylen=strlen(key);
	msglen=strlen(input);
	strcpy(key1,key);
	for (i=0;i<keylen-1;i++) {
		input[msglen+i]='0';
	}
	for (i=0;i<keylen;i++)
	 temp[i]=input[i];
	for (i=0;i<msglen;i++) {
		quot[i]=temp[0];
		if(quot[i]=='0')
		 for (j=0;j<keylen;j++)
		 key[j]='0'; else
		 for (j=0;j<keylen;j++)
		 key[j]=key1[j];
		for (j=keylen-1;j>0;j--) {
			if(temp[j]==key[j])
			 rem[j-1]='0'; else
			 rem[j-1]='1';
		}
		rem[keylen-1]=input[i+keylen];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	printf("\nQuotient is ");
	for (i=0;i<msglen;i++)
	 printf("%c",quot[i]);
	printf("\nRemainder is ");
	for (i=0;i<keylen-1;i++)
	 printf("%c",rem[i]);
	printf("\nFinal data is: ");
	for (i=0;i<msglen;i++)
	 printf("%c",input[i]);
	for (i=0;i<keylen-1;i++)
	 printf("%c",rem[i]);
	 //if (rem ==0)
	 //printf("Error in the code");
	 //else
	 //printf("\nNo Error detected%d",rem);
	 //getch();
}

/* output
proglab@proglab:~$ gcc crc.c
crc.c: In function ‘main’:
crc.c:11:2: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
  scanf("%c", &input);
  ^
proglab@proglab:~$ ./a.out
Enter Data: 101010

Quotient is 1
Remainder is 11111
Final data is: 111111proglab@proglab:~$ 

*/
