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
	//实现：李国豪
}
void DeleteRecord(int fileid, int page, short RID)
{
	//实现：金嘉宇
}
void ChangeRecord(int fileid, int page, short RID, DB_Record newrec)
{
	//实现: 周琳钧
}

#ifdef __cplusplus
}
#endif