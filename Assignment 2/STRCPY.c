#include<stdio.h>
#include<string.h>

// Program to copy string2 at the place of string1

void getString(char* str1,char* str2);
char* stringCopy(char* dest , char* src);

int main()
{

	char str1[50];
	char str2[50];

	getString(str1,str2);

	printf("String 1 before copying: %s\n",str1);
	printf("string 2 before copying: %s\n\n",str2);

	stringCopy(str2,str1);

	printf("String 1 after copying: %s\n",str1);
	printf("string 2 after copying: %s\n\n",str2);

	printf("\n \nPress enter key to continue");
	getchar();
	getchar();


	return 0;
}

void getString(char* str1,char* str2)
{
	printf("Enter 1st string: ");
	scanf("%s",str1);
	printf("Enter 2nd string: ");
	scanf("%s",str2);
}

char* stringCopy(char* dest, char* src)
{
	int i=0;
	while(*(src+i)!='\0')
	{
		dest[i] = src[i] ;
		i++;
	}
	dest[i] = '\0';
	return dest;
}
