#include<stdio.h>
#include<string.h>

void getStrings(char* str1);
char* stringReverse(char* str1);
int main()
{
	char str1[50];
	char* ptr;

	getStrings(str1);

	printf("String before reversing : %s\n",str1);

	ptr = stringReverse(str1);

	printf("Reversed String is:  %s\n",ptr);

	printf("\nPress enter key to continue");
	getchar();
	getchar();

	return 0;
}

void getStrings(char* str1)
{
	printf("Enter String which you want to reverse: ");
	scanf("%s",str1);
}

char* stringReverse(char* str1)
{
	int len = strlen(str1);
	len = len-1;
	char temp;

	for(int i=0;i<(len/2);i++,len--)
	{
		temp = *(str1+i);
		*(str1+i)=*(str1+len); 
		*(str1+len)=temp;
	}
	//printf("%s",str1);
	return str1;
}
 

