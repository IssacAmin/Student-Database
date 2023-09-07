#include "SDB.h"

//functions definition

bool SDB_IsFull(student DB[])
{
	//use an iterator for size in a while loop
	// if the id and year are both zero then this is an
	//struct and considered empty
	uint8 size = 0;
	for(int i = 0; i < 10; i++)
	{
		if((DB[i].Student_ID) != 0 || (DB[i].Student_year) != 0)
			size++;

	}
	if(size >= 11)
		return true;
	else
		return false;

}

uint8 SDB_GetUsedSize(student DB[])
{
	//calculating each non- NULL element
	//the null elements are considered the student with
	//id and year set to zero(NULL Corresponded value)
	uint8 size = 0;
	for(int i = 0; i < 10; i++)
	{
		if((DB[i].Student_ID) != 0 && (DB[i].Student_year) != 0)
			size++;
	}
	return size;
}

bool SDB_AddEntry(student DB[])
{
	//check if database is full
	if(SDB_IsFull(DB))
	{
		printf("Database is Full\n");
		return false;
	}
	else{
		//calculate the index of the next empty slot
		uint8 index = 0;
		while(DB[index].Student_ID != 0 && DB[index].Student_year != 0)
			index++;
		//take student id
		printf("please enter (ID, Year)\neach separated by a space: \n");
		fflush(stdout);
		int id = 0;
		int studentyear =0;
		scanf("%d %d", &id, &studentyear);
		fflush(stdin);
		//check if student id already exist
		//if it doesn't ask for the rest of the information
		if(SDB_IsIdExist(id, DB) == 0)
		{
			 (DB[index].Student_ID) = id;
			 (DB[index].Student_year) = studentyear;
		printf("Please enter (Course 1 Id, Course 1 mark\n");
		fflush(stdout);
		scanf("%d %d", &(DB[index].Course1_ID),(&DB[index].Course1_grade));
		fflush(stdin);
		printf("Please enter (Course 2 Id, Course 2 mark\n");
		fflush(stdout);
		scanf("%d %d", &(DB[index].Course2_ID),&(DB[index].Course2_grade));
		fflush(stdin);
		printf("Please enter (Course 3 Id, Course 3 mark\n");
		fflush(stdout);
		scanf("%d %d", &(DB[index].Course3_ID),&(DB[index].Course3_grade));
		fflush(stdin);
		return true;
		}
		//if student id does exist do not complete the action
		else
		{
			printf("Student Id already exists\n");
			return false;
		}
	}
}

void SDB_DeletEntry (uint32 id, student DB[])
{
	//searching for id and setting all data members to zero as a null reference
	uint8 index = 0;
	for(int i =0; i< 10;i++)
	{
		if(DB[i].Student_ID == id)
		{
			index =i;
			break;
		}
	}
	//if id doesn't exist do not complete the action
		if(index > 10)
		{
			printf("Student id doesn't exist");
			return;
		}
		else
		{
			DB[index].Student_ID = 0;
			DB[index].Student_year = 0;
			DB[index].Course1_ID = 0;
			DB[index].Course1_grade = 0;
			DB[index].Course1_grade = 0;
			DB[index].Course2_ID = 0;
			DB[index].Course2_grade = 0;
			DB[index].Course3_ID = 0;
			DB[index].Course3_grade = 0;
		}
}
bool SDB_ReadEntry (uint32 id, student DB[]){
	uint8 index = 0;
	while(DB[index].Student_ID != id && index <= 9)
		index++;

	if(index >= 10)
	{
		printf("Student id doesn't exist");
		return false;
	}
	else{
	printf("Student id: %d\t Student year: %d\nCourse 1 ID: %d\t Course 2 mark: %d\n",DB[index].Student_ID,
			DB[index].Student_year,
			DB[index].Course1_ID,
			DB[index].Course1_grade);
	printf("Course 2 ID: %d\t Course 2 mark: %d\nCourse 3 ID: %d \t Course 2 mark: %d\n",
			DB[index].Course2_ID,
			DB[index].Course2_grade,
			DB[index].Course3_ID,
			DB[index].Course3_grade);
	return true;
	}

}
void SDB_GetList (uint8 * count, uint32 * list, student DB[]){
	*count = SDB_GetUsedSize(DB);
	int index = 0;
		for(int i = 0; i < 10; i++)
		{
			if((DB[i].Student_ID) != 0 || (DB[i].Student_year) != 0)
				list[index] = DB[i].Student_ID;
				index++;
		}
}

bool SDB_IsIdExist(uint32 id, student DB[]){
	//check if id exists
	int index = 10;
	for(int i =0; i < 10;i++)
	{
		if(DB[i].Student_ID == id)
		{
			index = i;
		}
	}
		if(index == 10)
			return false;
		else
			return true;
}
