#include "Global.h"
int exstrcpy(char* dst, char* src, int dstpos, int srcpos, int length)
{
	for(int i = 0;i<length;i++)
		dst[dstpos + i] = src[srcpos + i];
	return 1;
}
char* getsubstr(char* dst, int begin, int length)
{
	char* re = new char[length];
	for(int i = 0;i<length;i++)
		re[i] = dst[begin + i];
	return re;
}