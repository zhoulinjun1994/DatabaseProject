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
#include "Global.h"

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

void DB_RecordModule::InsertRecord(int fileid, DB_Record rec)
{
	//实现：李国豪
}
void DB_RecordModule::DeleteRecord(int fileid, int page, int RID)
{
	//实现：金嘉宇
}
int DB_RecordModule::ChangeRecord(int fileid, int page, int RID, DB_Record newrec)
{
	//实现: 周琳钧
	
	char* buf;
	int error;
	if(error = DBGetPage(fileid, page, &buf) != DB_OK)
	{
		printf("Error: %d",error);
		return DB_ERROR_RECORD_CANNOT_RENEW;
	}
	else
	{
		int dLength = ((DB_PAGE*)(buf - DB_PGHEADERSIZE))->pgheader.dataLength;
		if(dLength != DB_RECORDHEADERSIZE + newrec.h.getLength())
		{
			printf("Error: record length does not match for this file");
			return DB_ERROR_RECORD_CANNOT_RENEW;
		}
		DB_RecordHeader* oldRecordH = (DB_RecordHeader*)::getsubstr(buf, RID * dLength, DB_RECORDHEADERSIZE);
		newrec.h.setPage(page);
		newrec.h.setRID(RID);
		newrec.h.setNextList(oldRecordH->next);
		char* newRecord = new char[DB_RECORDHEADERSIZE];
		memcpy(newRecord, &newrec.h, DB_RECORDHEADERSIZE);
		::exstrcpy(buf, newRecord, RID * dLength, 0, DB_RECORDHEADERSIZE);
		::exstrcpy(buf, newrec.getRecord(), RID * dLength + DB_RECORDHEADERSIZE, 0, newrec.h.getLength()) ;
	}
	return DB_OK;
}

#ifdef __cplusplus
}
#endif