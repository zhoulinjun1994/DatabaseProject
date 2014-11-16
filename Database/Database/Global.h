#ifndef __GLOBAL__
#define __GLOBAL__
#ifdef __cplusplus
extern "C"
{
#endif


int exstrcpy(char* dst, char* src, int dstpos, int srcpos, int length);
char* getsubstr(char* dst, int begin, int length);


#ifdef __cplusplus
}
#endif
#endif