#include "SDB_APP.h"


void SDB_APP(student DB[])
{
	//user prompt
	int choice;
	//super loop to keep getting commands
	do
	{
		printf("1. To add entry, enter 1\n");
		printf("2. To get used size in database, enter 2\n");
		printf("3. To read student data, enter 3\n");
		printf("4. To get the list of all student IDs, enter 4\n");
		printf("5. To check is ID is existed, enter 5\n");
		printf("6. To delete student data, enter 6\n");
		printf("7. To check is database is full, enter 7\n");
		printf("8. To exit enter 0\n");
		fflush(stdout);
		scanf("%d", &choice);
		fflush(stdin);
		SDB_action(choice, DB);
	}while(choice != 0);
}
void SDB_action(uint8 choice, student DB[])
{
	int id = 0;
	uint32 arr[10];
	uint8 count;
	//switch case for each command
	switch(choice)
			{
			case 1:
				SDB_AddEntry(DB);
				break;
			case 2:
				printf("The Used Size: %d\n", SDB_GetUsedSize(DB));
				break;
			case 3:
				//asking for user id input
				printf("Enter Student Id to search for: \n");
				fflush(stdout);
				scanf("%d", &id);
				fflush(stdin);
				SDB_ReadEntry(id, DB);
				break;
			case 4:
				//asking for user id input
				SDB_GetList(&count, arr, DB);
				printf("ID Count: %d\n", count);
				printf("IDs: ");
				for(int i = 0; i < count; i++)
					printf("%d -", arr[i]);
				printf("\n");
				break;
			case 5:
				//asking for user id input
				printf("Enter Student Id to search for: \n");
				fflush(stdout);
				scanf("%d", &id);
				fflush(stdin);
				if(SDB_IsIdExist(id,DB))
					printf("Student Id exist in database\n");
				else
					printf("Student Id doesn't exist in database\n");
				break;
			case 6:
				//asking for user id input
				printf("Enter Student Id to search for: \n");
				fflush(stdout);
				scanf("%d", &id);
				fflush(stdin);
				SDB_DeletEntry(id, DB);
				printf("Successfully Deleted\n");
				break;
			case 7:
				if(SDB_IsFull(DB))
					printf("Database is full\n");
				else
					printf("Database is not full\n");
				break;
			case 0:
				printf("Thank you... Good Bye\n");
				break;
			default:
				printf("Choice is invalid... Try Again\n");
				break;
			}
}
