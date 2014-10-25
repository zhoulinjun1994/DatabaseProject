#ifndef __DBRECORD__
#define __DBRECORD__
#ifdef __cplusplus
extern "C"
{
#endif

#include "DBRecord.h"
//本类记录了空记录的page和rid
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
//链表，需要放在文件头，表示空记录的List，链表的插入和删除永远是针对head而言的，比如插入3,4,5([head]5->4->3[tail])，则删除时返回顺序为5,4,3
class DB_NodeList
{
public:
	DB_EmptyNode* head;
public:
	DB_NodeList():head(0){};
	void Insert(DB_EmptyNode* node);
	DB_EmptyNode* Delete();
};
//记录管理模块，主要包含新建文件、打开文件、关闭文件、删除文件、插入记录、删除记录、更新记录的功能
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