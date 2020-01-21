#include<stdio.h>
#include<string.h>
#include<windows.h>

/*Input employee information from the user including his employee id, name, address,
salary,birth date and date of joining. Find the age of person when he joined company 
(in years) and his experience till date (in months). Also print the date when his
probation period is over, assuming that probation period is of 90 days from date 
of joining.*/
typedef enum{EXIT,INPUT_EMPLOYEE_INFORMATION,DISPLAY_EMPLOYEE_INFORMATION}MENU;


typedef struct date 
{  
	int dd;  
	int mm;  
	int yyyy;
}DATE1; 

typedef struct employee
{
	int Employee_Id;
	char Name[20];
	char Address[50];
	float Salary;
	DATE1  Date_Of_Birth;
	DATE1 Date_Of_Joining;

}emp;

 void TakeEmployeeInformation(emp* employ)
 {
 	printf("\nEnter Employee ID: ");
 	scanf("%d",&employ->Employee_Id);
 	//printf("\nEmployee ID IS: %d\n",employ->Employee_Id);
 	getchar();
 	printf("Enter Employee Name: ");
 	gets(employ->Name);
 	//printf("%s",employ->Name);
 	printf("Enter Employee Address: ");
 	gets(employ->Address);
 	//printf("%s",employ->Address);
 	printf("Enter Employee Salary: ");
 	scanf("%d",&employ->Salary);

 	printf("Enter date of birth in [dd mm yyyy]: ");
 	scanf("%d %d %d",&employ->Date_Of_Birth.dd,&employ->Date_Of_Birth.mm,&employ->Date_Of_Birth.yyyy);

 	//printf("\nDOB : %02d/%02d/%02d\n",employ->Date_Of_Birth.dd,employ->Date_Of_Birth.mm,employ->Date_Of_Birth.yyyy );

 	printf("\nEnter date of Joining [dd mm yyyy]: ");
 	scanf("%d %d %d",&employ->Date_Of_Joining.dd,&employ->Date_Of_Joining.mm,&employ->Date_Of_Joining.yyyy);

 }
 void ShowEmployeeInformation(emp* employ)
 {
 	int age_of_person_at_time_of_joining;
 	int employee_experience_till_date;
 	int ending_month_of_probation_period=employ->Date_Of_Joining.mm;
 	printf("The Age of person at time of joining[in years] is: %d\n",employ->Date_Of_Joining.yyyy - employ->Date_Of_Birth.yyyy );

 	SYSTEMTIME str_t; 
	GetSystemTime(&str_t);
	if(employ->Date_Of_Joining.yyyy != str_t.wYear)

	employee_experience_till_date = (str_t.wYear*12 + str_t.wMonth)- (employ->Date_Of_Joining.yyyy*12 +employ->Date_Of_Joining.mm);
	printf("Employee Experience till date[in months] : %d\n",employee_experience_till_date );
	//ending_month_of_probation_period = (employ->Date_Of_Joining.mm + 3)%12;
	for(int i=0;i<3;i++) 
		{
			if(1<=ending_month_of_probation_period<12)
			{
				ending_month_of_probation_period++; 
			}
			else if(ending_month_of_probation_period==12)
			{
				ending_month_of_probation_period=1;
			}
		}
	printf("Ending month of probation period : %d\n",ending_month_of_probation_period);
 }

int options() 
{
	int op; 
	printf("Enter \n 0]EXIT \n 1]INPUT_EMPLOYEE_INFORMATION \n 2]DISPLAY_EMPLOYEE_INFORMATION\n");
	scanf("%d",&op);
	return op;
}

int main()
{
	emp employee;
	int op;
	while((op=options())!=EXIT)
	{
	//printf("%d\n",op);
		switch(op)
		{
			case INPUT_EMPLOYEE_INFORMATION:
				TakeEmployeeInformation(&employee);
				break;
			case DISPLAY_EMPLOYEE_INFORMATION:
				ShowEmployeeInformation(&employee);
				break;
		}

	}

	return 0;
}