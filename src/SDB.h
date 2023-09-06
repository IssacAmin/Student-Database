#ifndef _SDB
#define _SDB

#include <stdio.h>
#include "STD.h"

typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;

} student;


bool SDB_IsFull(student DB[]);
uint8 SDB_GetUsedSize(student DB[]);
bool SDB_AddEntry(student DB[]);
void SDB_DeletEntry (uint32 id, student DB[]);
bool SDB_ReadEntry (uint32 id, student DB[]);
void SDB_GetList (uint8 * count, uint32 * list, student DB[]);
bool SDB_IsIdExist(uint32 id, student DB[]);


#endif
