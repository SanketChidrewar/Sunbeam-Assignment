#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//A CSV file contains movies data in given form. Read the file and load data into 
//a singly linked list of movie objects. Also give facility to find movies by 
//name and by genre.
//movieid,title,genres
//1,Toy Story (1995),Adventure|Animation|Children|Comedy|Fantasy
//2,Jumanji (1995),Adventure|Children|Fantasy
//3,Grumpier Old Men (1995),Comedy|Romance
//4,Waiting to Exhale (1995),Comedy|Drama|Romance
//5,Father of the Bride Part II (1995),Comedy
//6,Heat (1995),Action|Crime|Thriller
//7,Sabrina (1995),Comedy|Romance
//8,Tom and Huck (1995),Adventure|Children
//9,Sudden Death (1995),Action
//10,GoldenEye (1995),Action|Adventure|Thriller

typedef enum {EXIT,FIND_MOVIE_BY_NAME,FIND_MOVIE_BY_GENRE,DISPLAY_ALL_DATA}MENUOPERATIONS;

typedef struct movie
{
	char movieid[10];
	char title[50];
	char genres[50];
	struct movie *next;
}MOVIE_DATA;

void LOAD_CSV_FILE_DATA_TO_SLL();
int menuoption();
void addlast(MOVIE_DATA* ptr);
void dislayLL(MOVIE_DATA* ptr);
void findMovieByName(MOVIE_DATA* ptr);
void findMovieByGenre(MOVIE_DATA* ptr);

void LOAD_CSV_FILE_DATA_TO_SLL()
{
	FILE *fp;
	fp = fopen("F:\\C-DAC Assignment\\SUNBEAM PRE-JOINING ASSIGNMENT\\Assignment 8\\moviedata.txt","r");
	if(fp==NULL)
	{
		printf("###ERROR WHILE OPENING FILE ###\n");
		exit(1);
	}
	char buffer[100];

	while(fgets(buffer,100,fp)!=NULL)
	{

		MOVIE_DATA * ptr = (MOVIE_DATA*)malloc(sizeof(MOVIE_DATA));
		if(ptr==NULL)
		{
			printf("###ERROR CREATING MEMORY USING MALLOC###\n");
			exit(1);
		}
		char *buffer_ptr = strtok(buffer,",");
			 //printf("%s\t",buffer_ptr);
			  strcpy(ptr->movieid,buffer_ptr);
				//printf("movie_id = %s",ptr->movieid);
			 buffer_ptr = strtok(NULL,",");
			 //printf("%s\t",buffer_ptr);
			  strcpy(ptr->title,buffer_ptr);
			 buffer_ptr = strtok(NULL,",");
			 //printf("%s\t",buffer_ptr);
			 strcpy(ptr->genres,buffer_ptr);

			 addlast(ptr);

		printf("\n");
	}
}
int menuoption()
{
	int menu_option=0;
	printf("\n############################################\n");
	printf("ENTER ONE OF THE BELOW OPTION TO FIND MOVIE\n");
	printf("0]EXIT\n1]FIND_MOVIE_BY_NAME\n2]FIND_MOVIE_BY_GENRE\n3]DISPLAY_ALL_DATA");
	printf("\nENTER OPTON:");
	scanf("%d",&menu_option);
	return menu_option;
}

MOVIE_DATA* head =NULL;

void addlast(MOVIE_DATA* ptr)
{
	MOVIE_DATA* temp =head;
	if(head==NULL)
	{
		ptr->next=NULL;
		head = ptr;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next=NULL;
	}
}

void findMovieByName(MOVIE_DATA* ptr)
{
	MOVIE_DATA* temp = ptr;
	if(temp==NULL)
	{
		printf("###LIST IS EMPTY###\n");
		exit(1);
	}
	char str[50];
	int flag =0;
	printf("ENTER MOVIE NAME TO BE SEARCHED \n");
	getchar();
	scanf("%[^\n]%*c",str);
	strlwr(str);
	//printf("string = %s",str);
	while(temp!=NULL)
	{
		//printf("HELLO 1\n");
		if((strstr(temp->title,str))!=NULL)
		{
			//printf("HELLO 2\n");
			flag =1;
			printf("%s -> %s -> %s \n",temp->movieid,temp->title,temp->genres);
		}
		temp = temp->next;
	}
	if(flag ==0)
	{
		printf("DATA IS NOT PRESENT\n");
	}
}

void findMovieByGenre(MOVIE_DATA* ptr)
{
	MOVIE_DATA* temp = ptr;
	if(temp==NULL)
	{
		printf("###LIST IS EMPTY###\n");
		exit(1);
	}
	char str[50];
	int flag =0;
	printf("ENTER GENERE OF MOVIE TO BE SEARCHED \n");
	getchar();
	scanf("%[^\n]%*c",str);
	strlwr(str);
	//printf("string = %s",str);
	while(temp!=NULL)
	{
		//printf("HELLO 1\n");
		if((strstr(temp->genres,str))!=NULL)
		{
			//printf("HELLO 2\n");
			flag =1;
			printf("%s -> %s -> %s \n",temp->movieid,temp->title,temp->genres);
		}
		temp = temp->next;
	}
	if(flag ==0)
	{
		printf("DATA IS NOT PRESENT\n");
	}
}

void dislayLL(MOVIE_DATA* ptr)
{
	MOVIE_DATA* temp = ptr;
	if(temp==NULL)
	{
		printf("###LIST IS EMPTY###\n");
	}
	while(temp!=NULL)
	{
		printf("%s -> %s -> %s \n",temp->movieid,temp->title,temp->genres);
		temp = temp->next;
	}
}

int main()
{	
	LOAD_CSV_FILE_DATA_TO_SLL();
	int op=0;
	while(op=menuoption())
	{
		switch(op)
		{
			case FIND_MOVIE_BY_NAME:
				findMovieByName(head);
				break;
			case FIND_MOVIE_BY_GENRE:
				findMovieByGenre(head);
				break;
			case DISPLAY_ALL_DATA:
				dislayLL(head);
				break;
			default:
				printf("Enter Correct option \n");
				break;
		}
	}
	return 0;
}