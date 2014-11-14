#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <Windows.h>
#include "DBRecordModule.h"
#include "DBFile.h"
#include "DBFBuf.h"
#include "DBPageManager.h"
#include "DBIndexManager.h"
#include "DBError.h"

void DB_RecordModule::CreateDataFile(char* filename)
{
	int error;
	if((error = DBCreateFile(filename))!=DB_OK)
	{
		DBPrintError(error);
	}
}

int DB_RecordModule::OpenDataFile(char* filename)
{
	int error;
	if((error = DBOpenFile(filename)) < 0)
	{
		DBPrintError(error);
	}
	return error;
}

void DB_RecordModule::DeleteDataFile(char* filename)
{
	int error;
	if((error = DBDestroyFile(filename))!=DB_OK)
	{
		DBPrintError(error);
	}
}

void DB_RecordModule::CloseDataFile(int fileid)
{
	int error;
	if((error = DBCloseFile(fileid))!=DB_OK)
	{
		DBPrintError(error);
	}
}

void InsertRecord(int fileid, DB_Record rec)
{
	//ʵ�֣������
}
void DeleteRecord(int fileid, int page, short RID)
{
	//ʵ�֣������
}
void ChangeRecord(int fileid, int page, short RID, DB_Record newrec)
{
	//ʵ��: ���վ�
}

#ifdef __cplusplus
}
#endif