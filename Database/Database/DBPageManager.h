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

	//ע�⣺���������bufָ�����ҳ���ݵ���ʼλ�ã�Ҳ����˵��������ҳͷ��������ȡ����ҳ��Ϣ����ʹ��*(*(DB_PAGE**)buf - DB_PGHEADERSIZE)
	int DBGetPage(int fileid, int pageid, char** buf);
	int DBGetFirstPage(int fileid, char** buf);
	int DBGetNextPage(int fileid, int pageid, char** buf);
	//ע�⣬��������Ƿ���ҳͷ����ʼλ�ã���һ��Ҫ��DB_GetPage����������
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