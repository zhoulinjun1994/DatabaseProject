#ifndef __DBRECORDMODULE__
#define __DBRECORDMODULE__
#ifdef __cplusplus
extern "C"
{
#endif

#include "DBRecord.h"

//记录管理模块，主要包含新建文件、打开文件、关闭文件、删除文件、插入记录、删除记录、更新记录的功能
class DB_RecordModule
{
public:
	void CreateDataFile(char* filename);
	int OpenDataFile(char* filename);
	void DeleteDataFile(char* filename);
	void CloseDataFile(int fileid);
	void InsertRecord(int fileid, DB_Record rec);
	void DeleteRecord(int fileid, int page, int RID);
	int ChangeRecord(int fileid, int page, int RID, DB_Record newrec);
};


#ifdef __cplusplus
}
#endif
#endif