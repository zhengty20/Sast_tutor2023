#include "mystring.h"

void Build_BC(String& P, int* bc) {
	int m = P.StrLength();
	for (int i = 0; i < 256; i++) {
		bc[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		bc[int(P[i])] = i;
	}
}

void Build_GS(String& P, int* suffix, bool* prefix) {
	int m = P.StrLength();
	for (int i = 0; i < m; i++) {        
		suffix[i] = -1;                  
		prefix[i] = false;
	}
	for (int i = 0; i < m - 1; i++) {
		int j = i, k = 1;                 
		while (j >= 0 && P[j] == P[m - k]) {
			suffix[k] = j;          
			--j; ++k;
		}
		if (j == -1)  prefix[k - 1] = true;
	}
}

int move(int* suffix, bool* prefix, int j, int m) {
	int k = m - 1 - j;                     
	if (suffix[k] != -1) {
		return j - suffix[k] + 1;
	}
	for (int r = j + 2; r <= m - 1; r++) {
		if (prefix[m - r]) {
			return r;
		}
	}
	return m; 
}

int Horspool(String& T, String& P) {
	int n = T.StrLength();
	int m = P.StrLength();
	int bc[256];
	Build_BC(P, bc);
	int pos = 0;                                 
	while (pos <= n - m) {
		int j = m - 1;
		while (j >= 0 && P[j] == T[pos + j]) --j;
		if (j == -1) return pos;                
		pos += max(1, j - bc[T[pos + j]]);      
	}
	return -1;                                 
}

int BM_Match(String& T, String& P) {
	int n = T.StrLength();
	int m = P.StrLength();

	int bc[256];
	bool* prefix = new bool[m];
	int* gs = new int[m];
	Build_BC(P, bc);
	Build_GS(P, gs, prefix);

	int i = 0;
	while (i <= n - m) {
		int j = m - 1;
		while (j >= 0 && P[j] == T[i + j]) {
			--j;
		}
		if (j == -1) {
			return i;
		}
		int x = j - bc[int(T[i + j])];
		int y = 0;
		if (j < m - 1) {
			y = move(gs, prefix, j, m);
		}
		i += max(x, y);
	}
	return -1;
}