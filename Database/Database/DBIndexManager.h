#ifndef _DBINDEXMANAGER_H_
#define _DBINDEXMANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif 

#define IX_OK       1
#define IX_FAIL     0
#define EOIX       (-2)
#define MAXKEY      100
#define NUM_BUFS    8
#define MAX_LEVELS  8
#define IXB_SIZE    1024
#define IXB_SPACE  (IXB_SIZE - sizeof(int) - sizeof(long) * 2)

	typedef long RECPOS;

	typedef struct                    /*  entry structure in index        */
	{  
		RECPOS   idxptr;             /*  points to lower index level     */
		RECPOS   recptr;             /*  points to data record           */
		char     key[MAXKEY];        /*  start of record key             */
	}  ENTRY;

	typedef struct                    /*  index record format             */
	{  
		RECPOS   brec;	              /*  position in index file          */
		/*  or location of next free block  */
		int      bend;		          /*  first unused block location     */
		RECPOS   p0;                  /*  points to next level            */
		char     entries[IXB_SPACE];  /*  here are the key entries        */
	}  BLOCK;

	typedef struct                    /*  disk file info                  */
	{  
		RECPOS   ff;                  /*  location of first free block    */
		int      nl;                  /*  number of index levels          */
	}  IX_DISK;

	typedef struct                    /*  memory buffer pool of indx blks */
	{  
		int      dirty;               /*  true if changed                 */
		int      handle;              /*  index file handle               */
		int      count;               /*  number of times referenced      */
		BLOCK    mb;
	}  MEMBLOCK;

	typedef struct
	{  
		MEMBLOCK     cache [ NUM_BUFS ];
	}  IX_BUFFER;

	typedef struct                    /*  in-memory index descriptor      */
	{  
		int      ixfile;
		int      level;              /*  level in btree                  */
		int      duplicate;          /*  no duplicate keys if 0          */
		struct
		{  
			RECPOS    cblock;       /*  position in index file          */
			int       coffset;      /*  current offset within block     */
		}  pos [ MAX_LEVELS ];
		BLOCK    root;               /*  root index record               */
		IX_DISK  dx;
	}  IX_DESC;

	int open_index(char* name, IX_DESC* pix, int dup);
	int close_index(IX_DESC* pix);
	int make_index(char* name,IX_DESC* pix, int dup);
	int first_key(IX_DESC* pix);
	int last_key(IX_DESC* pix);
	int next_key(ENTRY* pe, IX_DESC* pix);
	int prev_key(ENTRY* pe, IX_DESC* pix);
	int find_key(ENTRY* pe, IX_DESC* pix);
	int add_key(ENTRY* pe, IX_DESC* pix);
	int locate_key(ENTRY* pe, IX_DESC* pix);
	int delete_key(ENTRY* pe, IX_DESC* pix);
	int find_exact(ENTRY* pe, IX_DESC* pix);

	int OpenIndex(char* name, int dup);
	int CloseIndex();
	int InsertKey(char* key, int fileid, int pageid);
	int RemoveKey(char* key);
	int SearchIndex(const char* key, int* fileid, int* pageid);

#ifdef __cplusplus
}
#endif 

#endif