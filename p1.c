#include<stdio.h>
#define MAXSIZE 10

int hash[MAXSIZE];

int hashfunc(int n, int i)
{
	return ((n%MAXSIZE)+i)%MAXSIZE;
}

void hashput(int val)
{
	int i,hval;
	for(i=0;i<MAXSIZE;i++)
	{
		hval=hashfunc(val,i);
		if(hash[hval]==0)
		{
			printf("Val = %d\n",val);
			hash[hval]=val;
			printf("Value inserted successfully\n");
			return;
		}
	}
	printf("Value could not be inserted\n");
}

void hashsearch(int val)
{
	int i,hval;
	for(i=0;i<MAXSIZE;i++)
	{
		hval=hashfunc(val,i);
		if(hash[hval]==val)
		{
			printf("%d found at index %d\n",val,hval);
			return;
		}
	}
	printf("Value not found\n");
}

void deletehash(int val)
{
	int i,hval;
	for(i=0;i<MAXSIZE;i++)
	{
		hval=hashfunc(val,i);
		if(hash[hval]==val)
		{
			hash[hval]=0;
			return;
		}
	}
	printf("Value not found\n");
}

void display()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		printf("%d ",hash[i]);
	}
	printf("\n");
}

int main()
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	hash[i]=0;
	int choice;
	int val;
	while(1)
	{
		printf("MENU\n1. INSERT\n2. SEARCH\n3. Delete\n4. DISPLAY\n5. EXIT\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data : ");
				scanf("%d",&val);
				hashput(val);
				break;
			case 2:
				printf("Enter data to search : ");
				scanf("%d",&val);
				hashsearch(val);
				break;
			case 3:
				printf("Enter data to delete : ");
				scanf("%d",&val);
				deletehash(val);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank you\n");
				return 0;
			default:
				printf("Invalid input");
		}
	}
}
