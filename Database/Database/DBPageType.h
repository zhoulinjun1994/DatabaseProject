#ifndef _DBPAGETYPE_
#define _DBPAGETYPE_

#include "DBFUtility.h"

typedef struct
{
	int nextfree;
	int pageID;

	int pg_nextpage;
	int pg_prevpage;

	//reserved attributes:
	int objID;
	int lsn;
	int slotCnt;//每个页面记录的最大值
	int level;
	int indexID;
	int freeData;
	int pminlen;
	int freeCnt;
	int reservedCnt;
	int xactreserved;
	int tornBits;
	int flagBits;
	int dataLength;//每个记录的长度
}DB_PGHEADER;

typedef struct
{
	DB_PGHEADER pgheader;
	char pgdata[DB_PGSIZE];

}DB_PAGE;

typedef struct BUF_PAGE
{
	struct BUF_PAGE* nextpage;
	struct BUF_PAGE* prevpage;
	short dirty;
	short used;
	short inbuf;
	int fileid;
	int pageid;
	int lrucnt;
	DB_PAGE page;

}BUF_PAGE;

#endif