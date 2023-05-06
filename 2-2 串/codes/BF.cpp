#include "mystring.h"

int BruteForceMatch(String& T, String& P)
{
	int n = T.StrLength();
	int m = P.StrLength();
	if (n < m || m == 0 || n == 0) return -1;   //若模式串长度大于目标串，或其一为空串，匹配必然失败
	int i = 0, j = 0;
	while (j < m && i < n) {          //自左向右逐次比对
		if (T[i] == P[j]) { i++; j++; }       //若匹配，转到下一字符串
		else { i -= j - 1; j = 0; }           //失配，则T回退、P复位
		if (j == m) return i - j;             //匹配成功，返回对齐位置
	}
	return -1;                                //匹配失败
}