
#include<stdio.h>
#include <Windows.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include "DBFile.h"
#include "DBFBuf.h"
#include "DBPageManager.h"
#include "DBIndexManager.h"
#include "DBError.h"
#include "DBRecord.h"
#include "DBRecordModule.h"


int main()
{
	int pageid;
	int fileid;
	char* buf;
	HANDLE hThread;
	int error;
	int found;
	int i;
	int k;
	int j;
	char key[100];

	DBInit();
	if((error = OpenIndex("Index.idx", 1))!=IX_OK)
	{
		DBPrintError(error);
	}
	hThread = BufCheck();

	if((error = DBCreateFile("file1"))!=DB_OK)
	{
		DBPrintError(error);
	}
	if((error = DBCreateFile("file2"))!=DB_OK)
	{
		DBPrintError(error);
	}

	if((error = DBOpenFile("file1"))!=0)
	{
		DBPrintError(error);
	}
	if((error = DBOpenFile("file2"))!=1)
	{
		DBPrintError(error);
	}
	for(i=0; i<14; i++)
	{
		if((error = DBAllocPage(0, &pageid, (DB_PAGE**)&buf, 34))!=DB_OK)
		{
			DBPrintError(error);
		}
		buf += DB_PGHEADERSIZE;
		for(j=0; j<DB_PGSIZE; j++)
			buf[j] = 87;
		DBPageFix(0, pageid);
		sprintf(key, "file0_page%d", i);
		if((error = InsertKey(key, 0, pageid))!=IX_OK)
		{
			DBPrintError(error);
		}
		SuspendThread(hThread);
		printf("FileID: 0  Pageid: %d.  File --> Buffer.\n", pageid);
		ResumeThread(hThread);
	}

	
	for(i=0; i<14; i++)
	{
		if((error = DBAllocPage(1, &pageid, (DB_PAGE**)&buf, 34))!=DB_OK)
		{
			DBPrintError(error);
		}
		buf += DB_PGHEADERSIZE;
		for(j=0; j<DB_PGSIZE; j++)
			buf[j] = 89;
		DBPageFix(1, pageid);
		sprintf(key, "file1_page%d", i);
		if((error = InsertKey(key, 1, pageid))!=IX_OK)
		{
			DBPrintError(error);
		}
		SuspendThread(hThread);
		printf("FileID: 1  Pageid: %d.  File --> Buffer.\n", pageid);
		ResumeThread(hThread);
	}	

	DB_Record rrr(6);
	printf("-------------------------------%d\n",sizeof(rrr));
	rrr.h.setPage(0);
	rrr.h.setRID(0);
	char* test = new char[6];
	for(int i = 0;i<6;i++)
		test[i] = 'X';
	rrr.setRecord(test);
	DB_RecordModule ccc;
	ccc.ChangeRecord(0, 0, 0, rrr);
	ccc.ChangeRecord(0, 0, 1, rrr);


	if(SearchIndex("file0_page9", &fileid, &pageid)==IX_OK)
	{
		printf("Page Found.  FileID: %d  PageID: %d\n", fileid, pageid);
	}

	for(i=0; i<5; i++)
	{
		SuspendThread(hThread);
		if((error = DBGetPage(1, i, &buf))!=DB_OK)
		{
			DBPrintError(error);
		}
		else
			printf("Get Page:   FileID: 1  Pageid: %d.\n", i);
		ResumeThread(hThread);
	}

	printf("Sleep for 2 seconds\n");
	Sleep(2000);
	DBGetPage(1, 3, &buf);
	DBPageUnfix(1, 3);
	DBPageUsed(1, 3);
	printf("Sleep for 6 seconds\n");
	//printf(buf);
	printf("\n");
	Sleep(6000);
	DBPageRelease(1, 3, TRUE);
	DBDisposePage(1, 3);
	printf("Sleep for 3 seconds\n");
	Sleep(3000);
	printf("%d\n", strlen(buf));

	DBGetFirstPage(0, &buf);
	DBPageUsed(0, 0);
	//printf(buf);
	printf("\n");
	buf[0] = '0';
	DBPageRelease(0, 0, TRUE);
	DBDisposePage(0, 0);
	DBGetFirstPage(0, &buf);
	//printf(buf);
	printf("\n");
	DBGetNextPage(1, 1, &buf);
	//printf(buf);
	printf("\n");
	DBCloseFile(0);
	DBCloseFile(1);
	CloseIndex();
	system("pause");
	return 0;
}

#ifdef __cplusplus
}
#endif
