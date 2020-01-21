#include<stdio.h>
#include<string.h>
// Program to concat string2 at the end of string1

void getStrings(char* str1, char* str2);
char * stringConcat(char* dest, char* src);

int main()
{

	char str1[30];
	char str2[30];

	getStrings(str1 , str2);

	printf("Strings before Concat Operation\nString1 = %s \nString2 = %s ",str1,str2);

	stringConcat(str1, str2);

	printf("\n\nStrings after Concat Operation\nString1 = %s \nString2 = %s ",str1,str2);

	printf("\n \nPress enter key to continue");
	getchar();
	getchar();

	return 0;
} 

void getStrings(char* str1, char* str2)
{
	printf("Enter 1st string: ");
	scanf("%s",str1);
	printf("\nEnter 2nd String: ");
	scanf("%s",str2);

}


char * stringConcat(char* dest, char* src)
{
	int i=0;
	int j=0;
	while(*(dest+i)!='\0')
	{
		i++;
	}
	while(*(src+j)!=0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i]='\0';

	return dest;
}
