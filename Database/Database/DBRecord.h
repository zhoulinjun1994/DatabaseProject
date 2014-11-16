/*Record�����Ψһ��־�����Ե�ҳ�źͼ�¼�ţ�record��һ�������ռ䣬�����ɹ��캯��DB_Record�����䳤�ȡ�
*/
#ifndef __DBRECORD_H__
#define __DBRECORD_H__
#include "DBList.h"

#ifdef __cplusplus
extern "C"
{
#endif

class DB_RecordHeader
{
private:
	int page;
	int RID;
public:
	DB_List next;
private:
	int length;
public:
	DB_RecordHeader()
	{
		length = 0;
		next = DB_List();
	}
	DB_RecordHeader(int length)
	{
		length = length;
		next = DB_List();
	}
	int getPage()
	{
		return page;
	}
	void setPage(int pg)
	{
		this->page = pg;
	}
	int getRID()
	{
		return RID;
	}
	void setRID(int rid)
	{
		this->RID = rid;
	}
	void setLength(int l)
	{
		length = l;
	}
	int getLength()
	{
		return length;
	}
	void setNextList(DB_List d)
	{
		next.page = page;
		next.rid = RID;
		next.nextpage = d.nextpage;
		next.nextrid = d.nextrid;
	}
};

class DB_Record
{
public:
	DB_RecordHeader h;
private:
	char* record;
public:
	DB_Record(int length)
	{
		record = new char[length];
		h.setLength(length);
	}
	void setRecord(char* buf)
	{
		strcpy(record, buf);
	}
	char* getRecord()
	{
		return record;
	}
};

#ifdef __cplusplus
}
#endif

#endif