#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct
{
	int rollNO;
	char name[10];
}student;

int compareStruct(const void *pa, const void *pb)
{
	const student* p1=pa;
	const student* p2=pb;
	return (p1->rollNO - p2->rollNO);
}

int compareInt(const void *pa, const void *pb)
{
	const int *p1=pa;
	const int *p2=pb;
	return *p1-*p2;
}
int compareString(const void *pa, const void *pb)
{
	return strcmp(pa,pb);
}
int main()
{

	int arr[8]={5,10,4,10,42,38,24,3};
	char names[6][20]={"sanket","vaibhav","sarang","prashant","akshay","kartik"};
	student stud[5]={{1,"abc"},{3,"sde"},{6,"tes"},{2,"ytr"},{5,"ste"}};

	qsort(arr,8,sizeof(int),compareInt);
	printf("\n1]qsort on Array of integer :\n\n");
	for (int i = 0; i < 8; ++i)
	{
		printf("%d\t",arr[i]);
	}

	printf("\n");

	qsort(names,6,20,compareString);
	printf("\n2]qsort on Array of string :\n\n");
	for (int i = 0; i < 6; ++i)
	{
		printf("%s\t",names[i]);
	}

	printf("\n");

	qsort(stud,5,sizeof(student),compareStruct);
	printf("\n3]qsort on Array of strut :\n\n");

	for (int i = 0; i < 5; ++i)		
	{
		printf("id = %d \t name = %s\n",stud[i].rollNO,stud[i].name);
	}

	return 0;
}