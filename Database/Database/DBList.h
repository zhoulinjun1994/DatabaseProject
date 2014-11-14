#ifndef __DBLIST__
#define __DBLIST__
#ifdef __cplusplus
extern "C"
{
#endif


//本类记录了空记录的page和rid
class DB_List
{
public:
	int page;
	int rid;
	int nextpage;
	int nextrid;
public:
	DB_List():page(-1), nextpage(-1), rid(-1),nextrid(-1){};
	DB_List(int p, int r, int np, int nr):page(p), nextpage(np), rid(r), nextrid(nr){};
};

#ifdef __cplusplus
}
#endif
#endif