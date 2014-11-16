#ifndef __DBRECORDMODULE__
#define __DBRECORDMODULE__
#ifdef __cplusplus
extern "C"
{
#endif

#include "DBRecord.h"

//��¼����ģ�飬��Ҫ�����½��ļ������ļ����ر��ļ���ɾ���ļ��������¼��ɾ����¼�����¼�¼�Ĺ���
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