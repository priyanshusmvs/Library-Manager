#include<stdio.h>
#include<time.h>

struct item
{
	char name[25];
	float prc;
	int qnt;
};

int main()
{
time_t lt = time(NULL);
struct tm tm = *localtime(&lt);

char buyer[100];
int i,j,n,k=0,t,q,l;
float sum=0;
printf("Welcome to the LIBRARY! \nPlease provide the required details of the item available in your inventory.\n \nEnter number of books available:");
scanf("%d",&n);
struct item I[n],S[n];

for(i=0;i<n;i++)
{
printf("Book ID:%d\n",i+1);
printf("Name:");
scanf("%s",I[i].name);
printf("Price per book: Rs. ");
scanf("%f",&I[i].prc);
printf("No. of books: ");
scanf("%d",&I[i].qnt);
}
printf("\nThank you for setting up the inventory!");
printf("\nPress Enter to Continue");
while((getchar())!='\n');
while((getchar())!='\n');
for(l=1;l<=30;l++)
	printf("\n");

printf("\n-----------------------------------------------------------\n");
printf("*****LIBRARY Manager*****\n-----------------------------------------------------------\n\n1)Sale and invoice \n2)Store Details and Updation \nChoose the required option(-1 to end):");
scanf("%d",&k);

while(k!=-1)
{
switch(k)
{

case 1: printf("\nSales\n\n");
	printf("Enter -1 to print receipt\n");
	printf("Name of Customer:");
	scanf("%s",buyer);
	j=0;
	sum=0;
	printf("------------------------------------------------------------\n");
	printf("ID\t |Name\t\t |Price per item\t |Quantity\n------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
	printf("%d     \t  %s\t\t  Rs.%f\t ",i+1,I[i].name,I[i].prc);
	scanf("%d",&q);
	
	
	if(q==-1)
		break;
	
	else if(q>I[i].qnt)
		printf("                   OUT OF STOCK!-Only %d available\n",I[i].qnt);

	else if(q!=0)
		{
		//S[j]={0};
		sum+=I[i].prc*q;
		S[j]=I[i];
		S[j].qnt=q;
		I[i].qnt=I[i].qnt-q;
		j++;
		}
	}

	printf("\n\n------------------------------------------------------------\n**********CITY LIBRARY**********\n*****INVOICE*****\n------------------------------------------------------------\n");
	printf("\nName: %s \t\t Date: %2d/%2d/%4d %2d:%2d:%2d \n",buyer,tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("You have purchased the following items:\n\n");
	printf("------------------------------------------------------------\n");
	printf("S. No.\t |Name\t\t |Price per book\t |Quantity\t Amount\n------------------------------------------------------------\n");
	for(i=0;i<j;i++)
		printf("%d     \t  %s\t\t  Rs.%f\t %d\t  Rs.%f \n",i+1,S[i].name,S[i].prc,S[i].qnt,S[i].prc*S[i].qnt);
	printf("\n\nYour total amount is Rs. %f",sum);
	break;

case 2: printf("\nInventory\n\n");
	printf("ID\t Name\t\t Price per item\t Quantity \n\n");
	for(i=0;i<n;i++)
		printf("%d \t\t %s\t\t Rs.%f\t %d \n",i+1,I[i].name,I[i].prc,I[i].qnt);

	printf("Enter Item No. to update item details (-1 to go back):");
	scanf("%d",&t);
	while(t!=-1)
	{
	printf("\nBook ID:%d\n Name:%s\n Price per item: Rs.%f\n Number of books:%d\n\n",t,I[t-1].name,I[t-1].prc,I[t-1].qnt);
	printf("New Price per book: Rs.");
	scanf("%f",&I[t-1].prc);
	printf("Update Quantity of book: ");
	scanf("%d",&I[t-1].qnt);

	printf("Enter Book ID to update book details (-1 to go back):");
	scanf("%d",&t);
	}
	break;

default: printf("\nWrong input! Try again.");
}

printf("\nPress Enter to Continue");
while((getchar())!= '\n' );
while((getchar())!= '\n' );
for(l=1;l<=10;l++)
	printf("\n");

printf("\n-----------------------------------------------------------\n");
printf("*****LIBRARY Manager*****\n-----------------------------------------------------------\n\n1)Sale and invoice \n2)Store Details and Updation \nChoose the required option(-1 to end):");
scanf("%d",&k);
}
return 0;
}
