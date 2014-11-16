#ifndef _DBPAGEMANAGER_H_
#define _DBPAGEMANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "DBFile.h"
#include "DBFBuf.h"
#include "DBHash.h"

	short DBInvalidFileID(int fileid);
	short DBInvalidPageID(int fileid, int pageid);
	int DBFilePageChanged(int fileid, int pageid, BOOL dirty);

	//注意：这个函数的buf指向的是页数据的起始位置，也就是说，不包含页头，如果想获取整个页信息，请使用*(*(DB_PAGE**)buf - DB_PGHEADERSIZE)
	int DBGetPage(int fileid, int pageid, char** buf);
	int DBGetFirstPage(int fileid, char** buf);
	int DBGetNextPage(int fileid, int pageid, char** buf);
	//注意，这个函数是返回页头的起始位置，这一点要和DB_GetPage函数做区分
	int DBAllocPage(int fileid, int* pageid, DB_PAGE** page, int datalength);
	int DBDisposePage(int fileid, int pageid);
	int DBPageFix(int fileid, int pageid);
	int DBPageUnfix(int fileid, int pageid);
	int DBPageUsed(int fileid, int pageid);
	int DBPageRelease(int fileid, int pageid, int dirty);

#ifdef __cplusplus
}
#endif 

#endif