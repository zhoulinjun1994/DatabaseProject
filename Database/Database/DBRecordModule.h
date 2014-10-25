#ifndef __DBRECORD__
#define __DBRECORD__
#ifdef __cplusplus
extern "C"
{
#endif

#include "DBRecord.h"
//�����¼�˿ռ�¼��page��rid
class DB_EmptyNode
{
public:
	DB_EmptyNode* prev;
	int page;
	short rid;
	DB_EmptyNode* next;
public:
	DB_EmptyNode():prev(0),page(-1),rid(-1),next(0){};
	DB_EmptyNode(int p, short r):prev(0),page(p),rid(r),next(0){};
};
//������Ҫ�����ļ�ͷ����ʾ�ռ�¼��List������Ĳ����ɾ����Զ�����head���Եģ��������3,4,5([head]5->4->3[tail])����ɾ��ʱ����˳��Ϊ5,4,3
class DB_NodeList
{
public:
	DB_EmptyNode* head;
public:
	DB_NodeList():head(0){};
	void Insert(DB_EmptyNode* node);
	DB_EmptyNode* Delete();
};
//��¼����ģ�飬��Ҫ�����½��ļ������ļ����ر��ļ���ɾ���ļ��������¼��ɾ����¼�����¼�¼�Ĺ���
class DB_RecordModule
{
public:
	void CreateDataFile(char* filename);
	int OpenDataFile(char* filename);
	void DeleteDataFile(char* filename);
	void CloseDataFile(int fileid);
	void InsertRecord(int fileid, DB_Record rec);
	void DeleteRecord(int fileid, int page, short RID);
	void ChangeRecord(int fileid, int page, short RID, DB_Record newrec);
};


#ifdef __cplusplus
}
#endif
#endif