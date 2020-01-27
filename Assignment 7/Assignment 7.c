#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Implement doubly linked list of bank accounts. Each accont have information
//including id, type, balance and account holder. The account holder details 
//includes name, address & contact details. Write an menu-driven program to
//implement add first, add last, display all (forward), displ ay all
//(backword), find by account id, find by account holder name, delete all functionalities

typedef enum {EXIT,ADD_FIRST,ADD_LAST,DISPLAY_ALL_FORWORD,DISPLAY_ALL_BACKWORD,FIND_BY_ACC_ID,FIND_BY_ACC_HOL_NAME,DELETE_ALL_FUNCTIONALITY}MENUOPERATIONS;

typedef struct 
{
	char name[30];
	char address[30];
	long long int contact_no[15];
}ACCOUNT_HOLDER;

typedef struct NODE
{
	int id;
	char account_type[20];
	int balance;
	ACCOUNT_HOLDER ah;
	struct NODE* prev;
	struct NODE* next;
}BANK_ACCOUNT;

BANK_ACCOUNT * head = NULL;

int menuOption()
{
	int op;
	printf("\nENTER MENU OPTIONS TO PERFORM SPECIFIC OPERATION :\n");
	printf("0]EXIT\n1]ADD_FIRST\n2]ADD_LAST\n3]DISPLAY_ALL_FORWORD\n4]DISPLAY_ALL_BACKWORD\n5]FIND_BY_ACC_ID\n6]FIND_BY_ACC_HOL_NAME\n7]DELETE_ALL_FUNCTIONALITY\n");
	printf("menuOption :");
	scanf("%d",&op);
	return op;
}

 void takeAccountData(BANK_ACCOUNT* ptr)
 {
 	printf("\nEnter Account ID :");
 	scanf("%d",&ptr->id); 
 	printf("\nEnter Account Type :");
 	scanf("%s",ptr->account_type);
 	printf("\nEnter balance :");
 	scanf("%d",&ptr->balance);
	printf("\nEnter Name of account holder :");
	getchar();
 	scanf("%[^\n]%*c",ptr->ah.name); 
 	printf("\nEnter address of account holder :");
 	scanf("%[^\n]%*c",ptr->ah.address);
 	printf("\nEnter mobile number of account holder :");
 	scanf("%s",ptr->ah.contact_no);
 }

 void addElementAtFirst()
 {
 	BANK_ACCOUNT* ptr;
 	BANK_ACCOUNT* temp = head;
 	ptr = (BANK_ACCOUNT*)malloc(sizeof(BANK_ACCOUNT));
 	takeAccountData(ptr);
 	if(head == NULL)
 	{
 		head = ptr;
 		ptr->next = NULL;
 		ptr->prev = NULL;
 	}
 	else
 	{
 		ptr->next = head; 
 		head->prev = ptr;
 		//head->next = NULL;
 		ptr->prev = NULL;
 		head = ptr;
 	}
 }

 void addElementAtLast()
 {
 	BANK_ACCOUNT *ptr;
 	BANK_ACCOUNT *temp =head;

 	if(head==NULL)
 	{
 		addElementAtFirst();
 		return ;
 	}
 	else 
 	{
 			while(temp->next!=NULL)
 		{
 			temp = temp->next;
 		}
 		ptr = (BANK_ACCOUNT*)malloc(sizeof(BANK_ACCOUNT));
 		takeAccountData(ptr);
 		temp->next =ptr;
 		ptr->prev = temp;
 		ptr->next = NULL;
 	}
 }

void displayAllForword()
{
	BANK_ACCOUNT *temp =head;
	if(temp==NULL)
	{
		printf("\n###LIST IS EMPTY###\n");
		return ;
	}
	while(temp!=NULL)
	{
		printf("\nid = %d\nACC type= %s\nBal =%d\n",temp->id,temp->account_type,temp->balance);
		printf("name = %s\nAddress = %s\ncontact no =%s\n",temp->ah.name,temp->ah.address,temp->ah.contact_no);
		temp = temp->next;
	}
}

void displayAllBackword()
{
	BANK_ACCOUNT *temp =head;
	if(temp==NULL)
	{
		printf("\n###LIST IS EMPTY###\n");
		return ;
	}
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	while(temp!=NULL)
	{
		printf("\nid = %d\nACC type= %s\nBal =%d\n",temp->id,temp->account_type,temp->balance);
		printf("name = %s\nAddress = %s\ncontact no =%s\n",temp->ah.name,temp->ah.address,temp->ah.contact_no);
		temp = temp->prev;
	}
}

void fidByAccountId()
{
	BANK_ACCOUNT *temp =head;
	int id_no;
	int flag =0;
	
	if(head==NULL)
	{
		printf("\n###List is Empty###\n");
		return ;
	}
	else
	{
		printf("\nEnter id number to be searched :");
		scanf("%d",&id_no);
		while(temp!=NULL)
		{
			if(temp->id == id_no)
			{
				flag =1;
				printf("\nid = %d\nACC type= %s\nBal =%d\n",temp->id,temp->account_type,temp->balance);
				printf("name = %s\nAddress = %s\ncontact no =%s\n",temp->ah.name,temp->ah.address,temp->ah.contact_no);
			}
			temp = temp->next;
		}
		if(flag==0)
		{
		printf("\n###Id is not present in the list###\n");
		}
	}
}

void findByAccountHolderName()
{
	BANK_ACCOUNT *temp = head;
	char HolderName[30];
	int flag =0;
	if(head==NULL)
	{
		printf("\n###List is Empty###\n");
		return ;
	} 
	else
	{
		printf("\nEnter Account Holder name to be searched :");
		getchar();
		scanf("%[^\n]%*c",HolderName);
		while(temp!=NULL)
		{
			//printf("%s == %s\n",temp->ah.name,HolderName );
			//printf("%d\n",strcmp(temp->ah.name,HolderName));
			if((strcmp(temp->ah.name,HolderName))==0)
			{
				flag =1;
				printf("\nid = %d\nACC type= %s\nBal =%d\n",temp->id,temp->account_type,temp->balance);
				printf("name = %s\nAddress = %s\ncontact no =%s\n",temp->ah.name,temp->ah.address,temp->ah.contact_no);
			}
			temp = temp->next;
		}
		if(flag ==0)
		{
		printf("\n###ACC Holder Name is not present in the list###\n");
		}
	}
}

void deleteAllFunctionality()
{
	BANK_ACCOUNT *temp = head;
	if(temp==NULL)
	{
		printf("\n###LIST IS EMPTY###\n");
		return ;
	}
	BANK_ACCOUNT *prevTemp;
	while(temp!=NULL)
	{
		prevTemp = temp;
		temp=temp->next;
		free(prevTemp);
	}
	head = NULL;
	printf("\nSuccessfully Deleted All element\n");
}

int main()
{
	int op;
	//ACCOUNT_HOLDER.prev = NULL;
	//ACCOUNT_HOLDER.next = NULL;
	while((op=menuOption())!=EXIT)
	{
		switch(op)
		{
			case ADD_FIRST:
				addElementAtFirst();
				break;

			case ADD_LAST:
				addElementAtLast();
				break;

			case DISPLAY_ALL_FORWORD:
				displayAllForword();
				break;

			case DISPLAY_ALL_BACKWORD:
				displayAllBackword();
				break;
			case FIND_BY_ACC_ID:
				fidByAccountId();
				break;
			case FIND_BY_ACC_HOL_NAME:
				findByAccountHolderName();
				break;
			case DELETE_ALL_FUNCTIONALITY:
				deleteAllFunctionality();
				break;
			default:
				printf("\nEnter Valid menuOption\n");
		}
	}
	return 0;
}