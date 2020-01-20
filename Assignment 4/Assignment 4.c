#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Create an array of 10 books with details id, name, price. Sort array in descending 
//order of price using merge sort. Also sort array in ascending order of name using 
//library function qsort().

typedef struct
{
	int id;
	char name[30];
	int price;
}BOOK;

void printBooks(BOOK* books);
int compareStructBasedOnNames(const void* pa,const void*pb);
void mergeSort(BOOK *arr,int lb,int ub);
void merge(BOOK *arr,int lb,int mid, int ub);

void printBooks(BOOK *books)
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%5d\t%30s\t\t%10d\n",books[i].id,books[i].name,books[i].price);
	}
}

int compareStructBasedOnNames(const void* pa,const void*pb)
{
	const BOOK* p1=pa; 
	const BOOK* p2=pb;
	return strcmp(p1->name,p2->name);
}

void merge(BOOK *arr,int lb,int mid, int ub)
{
	BOOK b[20];
	int i=lb;
	int j=mid+1;
	int k=lb; 
	while((i<=mid) && (j<=ub)) 
	{
		if(arr[i].price >= arr[j].price)
		{
			b[k++]=arr[i++]; 
		}
		else if(arr[j].price>=arr[i].price)
		{
			b[k++]=arr[j++];
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k++]=arr[j++];
		}
	}
	else if(j>ub)
	{
		while(i<=mid)
		{
			b[k++]=arr[i++];
		}
	}

	for (int i = lb; i <= ub; ++i)
	{
		arr[i]=b[i];
	}
}

void mergeSort(BOOK *arr,int lb,int ub)
{
	// printf("%d\n", arr[mid].price);
	if (lb<ub)
	{
		int mid = (lb+ub)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
int main()
{
	BOOK books[10]={{1,"Let us C",100},{2,"Pointers in C",200},{3,"Java for begineers",150},{4,"Absolute begineers guide to c",350},{5,"Programming in objective c",250},{6,"pythone programming",130},{7,"DS through C",700},{8,"Programming with C",290},{9,"Test your C skills",470},{10,"C primer Plus",60}};
	
	// qsort(books,10,sizeof(BOOK),compareStructBasedOnNames);
	printf("Below is the list of books sorted in ascending order of name: \n");
	printBooks(books);

	printf("\n\n");

	printf("Below is the list of books sorted in descending order of book price: \n");
	mergeSort(books,0,9);
	printBooks(books);

	return 0;
}