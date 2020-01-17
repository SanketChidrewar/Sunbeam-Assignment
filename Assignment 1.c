#include <stdio.h>
#include<string.h>
// //without using strtok
// int main()
// {
// 	char arr[30];
// 	printf("enter the string");
// 	scanf("%s",arr);

// 	char *p = arr;
	
// 	int i=0;

// 	while(*(p+i)!='\0')
// 	{
// 		if(*(p+i)==',')
// 		{
// 			printf("\n");
// 			i++;
// 		}
// 		else
// 		{
// 			printf("%c", *(p+i));

// 		}
// 		i++;
// 	}

// 	return 0;
// }
//******************************************************************
//String tokenisation using STRTOK Function
	int main(int argc,char *argv[])
	{	
		char *ptr;

		ptr = strtok(argv[1],",");

		while(ptr!='\0')
		{
			printf("%s\n",ptr);
			ptr = strtok(NULL,",");
		}
		return 0;
	}