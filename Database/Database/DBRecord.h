/*Record类包含唯一标志其属性的页号和记录号，record是一段连续空间，可以由构造函数DB_Record生成其长度。
*/
#ifndef __DBRECORD_H__
#define __DBRECORD_H__
#include "DBList.h"

#ifdef __cplusplus
extern "C"
{
#endif

class DB_Record
{
private:
	int page;
	short RID;
	char* record;
public:
	DB_List next;
public:
	DB_Record(int length)
	{
		record = new char[length];
		next = DB_List();
	}
	char* getRecord()
	{
		return record;
	}
	void setRecord(char* rec)
	{
		strcpy(this->record, rec);
	}
	short getPage()
	{
		return page;
	}
	void setPage(int pg)
	{
		this->page = pg;
	}
	short getRID()
	{
		return RID;
	}
	void setRID(short rid)
	{
		this->RID = rid;
	}
};

#ifdef __cplusplus
}
#endif

#endif