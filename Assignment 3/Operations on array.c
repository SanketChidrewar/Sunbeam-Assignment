#include<stdio.h>
#include<stdlib.h>

/*Maintain an array of ten positive numbers. Initially all elements are set to zero (indicating array
is empty). Write a menu driven program to perform operations like add number, delete number,
find maximum number (along with its index), find minimum number (along with its index) and
sum of numbers. While adding number display available indexes and user can select any of them.
If no index is free, display appropriate message. Also while deleting number display available
indexes along with values and user can clear value there (set to zero).*/
typedef enum {EXIT=0,ADD,DELETE,FIND_MAX_NUMBER,FIND_MIN_NUMBER,SUM_OF_NUMBERS} operations;

int takeInput() 
{
	printf("Enter \n 0.EXIT\n 1. ADD\n 2.DELETE\n 3.FIND_MAX_NUMBER\n 4.FIND_MIN_NUMBER\n 5.SUM_OF_NUMBERS\n");
	int op;
	scanf("%d",&op);
	return op;  
}  
 
int CHECK_ARRAY_STATUS_TO_ADD_ELEMENT(int* arr_ptr)
{
	int count =0; 
	for(int i=0;i<10;i++) 
	{
		if(arr_ptr[i]==0)
		{
			count++;
		}
	}
	return count;
}

void ADD_ELEMENT_IN_ARRAY(int* arr_ptr)
{
	int number;
	int location;
	printf("Enter number which you want to add");
	scanf("%d",&number);
	printf("EMPTY INDEX LOCATION IN ARRAY ARE:\n");

	for(int i=0;i<10;i++)
	{
		if(arr_ptr[i]==0)
		{
			printf("%d\n",i);
		}
	}
	printf("\nEnter INDEX number where you want to add number: ");
	scanf("%d",&location);

	arr_ptr[location] = number;

	printf("\nSuccessfully added number = %d in array at index = %d \n",number,location);

}

int CHECK_ARRAY_STATUS_TO_DELETE_ELEMENT(int* arr_ptr)
{
	int count=0;
	for(int i=0;i<10;i++)
	{
		if(arr_ptr[i]==0)
		{
			count++;
		}
	}
	if (count==10)
	{
		return 0;
	}
	else
	{
		return count;
	}
}

void DELETE_ELEMENT_FROM_ARRAY(int* arr_ptr)
{
	int index;
	printf("Available element in array with there index location are");
	for (int i = 0; i < 10; ++i)
	{
		if(arr_ptr[i]!=0)
		{
			printf("arr_ptr[%d] = %d\n",i,arr_ptr[i]);
		} 
	}
	printf("Enter Index of a number Which you want to delete:");
	scanf("%d",&index);
	arr_ptr[index]=0;
 
	printf("\nNumber at Index %d is Successfully deleted\n",index);
}

void FIND_MAX_NUMBER_FROM_ARRAY(int* arr_ptr)
{
	int max = arr_ptr[0];
	int i=1; 
	while(i<10)
	{
		if(arr_ptr[i]>max)
		{
			max = arr_ptr[i];
		}
		i++;
	}

	printf("MAXIMUM NUMBER IN ARRAY IS: %d\n",max );
}

void FIND_MIN_NUMBER_FROM_ARRAY(int* arr_ptr)
{
	int min = arr_ptr[0];
	int i=1;
	while(i<10)
	{
		if(arr_ptr[i]<min)
		{
			min = arr_ptr[i];
		}
		i++;
	}

	printf("MINIMUM NUMBER IN ARRAY IS: %d\n",min );
}

void FIND_SUM_OF_NUMBERS_IN_ARRAY(int* arr_ptr)
{
	int sum=0;
	for (int i = 0; i < 10; ++i)	
	{
		sum = sum + arr_ptr[i];
	}

	printf("SUM OF NUMBERS IN ARRAY IS: %d\n",sum );
}

int main()
{
	int arr[10]={0};

	int op=0;
	int status;

	while((op=takeInput())!=EXIT)
	{ 
		//printf("HELLO \n");
		switch(op)
		{
			case ADD:
			status = CHECK_ARRAY_STATUS_TO_ADD_ELEMENT(arr);
			if(status!=0)
				ADD_ELEMENT_IN_ARRAY(arr);
			else
			{
				printf("ARRAY IS FULL");
			}
			break; 

			case DELETE:
			status = CHECK_ARRAY_STATUS_TO_DELETE_ELEMENT(arr);
			if(status!=0)
				DELETE_ELEMENT_FROM_ARRAY(arr);
			else
			{
				printf("ARRAY IS EMPTY");
			}
			break;

			case FIND_MAX_NUMBER:
				FIND_MAX_NUMBER_FROM_ARRAY(arr);

			break;

			case FIND_MIN_NUMBER:
				FIND_MIN_NUMBER_FROM_ARRAY(arr);

			break;

			case SUM_OF_NUMBERS:
				FIND_SUM_OF_NUMBERS_IN_ARRAY(arr);

			break;
		}

	}

	//printf("HELLO\n");

	return 0;
}