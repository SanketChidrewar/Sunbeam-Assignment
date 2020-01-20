#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int lb,int mid, int ub)
{
	int b[20]={0};
	int i=lb;
	int j=mid+1;
	int k=lb;
	while((i<=mid) && (j<=ub)) 
	{
		if(arr[i]<=arr[j])
		{
			b[k++]=arr[i++]; 
		}
		else if(arr[j]<=arr[i])
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

void mergeSort(int *arr,int lb,int ub)
{
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
	int arr[8]={3,5,1,6,8,2,9,4};

	mergeSort(arr,0,7);

	for (int i = 0; i < 8; ++i)
	{
		printf("arr[%d]=%d\n",i,arr[i] );
	}

	return 0;
}