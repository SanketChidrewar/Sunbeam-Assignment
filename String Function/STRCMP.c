#include<stdio.h>
#include<string.h>
// Program to Compair string1 with string1 if equal return 0 otherwise
// Return difference between ASCII VALUE of its character where it is not Equal.
// i.e. Compairing two string lexicographically.

void getStrings(char* str1, char* str2);
int stringCompair(char* str1, char* str2);

int main()
{

	char str1[30];
	char str2[30];
	int result;

	getStrings(str1 , str2);

	printf("Strings You have entered are \nString1 = %s \nString2 = %s \n\n",str1,str2);

	result = stringCompair(str1, str2);

	if(result!=0)
	{
		printf("Strings are Not Equal :%d",result);
	}
	else
		printf("Strings are Equal :%d",result);


	printf("\nPress enter key to continue");
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

int stringCompair(char* str1, char* str2)
{
	int i=0;

	while((*(str1+i)!='\0') && (*(str2+i)!='\0'))
	{
		if(*(str1+i)!=*(str2+i))
			{
				return (*(str1+i) - *(str2+i));
			}
		else
			{
				i++;
			}
	}

	return (*(str1+i) - *(str2+i));
}
