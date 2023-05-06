#include<iostream>
#include"mystring.h"
using namespace std;


char& String::operator[](int n)
{
	if (n >= 0 && n < DEFAULT_SIZE) return a[n];
	else cout << "Illegal Index!" << endl;
}

void String::ShowString()const
{
	cout << a << endl;
}

String::String(const char* S)
{
	int i = 0;
	while (S[i] != '\0') {
		a[i] = S[i];
		i++;
	}
	a[i] = '\0';
}

String::String(String& S)
{
	int i = 0;
	while (S[i] != '\0') {
		a[i] = S[i];
		i++;
	}
	a[i] = '\0';
}

void String::StrCopy(String& S)
{
	int i = 0;
	while (S[i] != '\0') {
		a[i] = S[i];
		i++;
	}
	a[i] = '\0';
}

void String::ClearString()
{
	//memset(a, '\0', sizeof(a) / sizeof(char));
	a[0] = '\0';
}

int String::StrCompare(String& T)const
{
	int i = 0;
	while (a[i] != '\0' && T[i] != '\0') {
		if (a[i] > T[i]) return 1;
		if (a[i] < T[i]) return -1;
		i++;
	}
	if (a[i] != '\0' && T[i] == '\0') return 1;
	if (a[i] == '\0' && T[i] != '\0') return -1;
	return 0;
}

bool String::StrEmpty()const
{
	if (a[0] == '\0') return true;
	return false;
}

int String::StrLength()const
{
	int i = 0;
	while (a[i] != '\0') i++;
	return i;
}

void String::Concat(String& S1, String& S2)
{
	int i = 0, j = 0;
	while (S1[i] != '\0') {
		a[i] = S1[i];
		i++;
	}
	while (S2[j] != '\0') {
		a[i + j] = S2[j];
		j++;
	}
	a[i + j] = '\0';
}

void String::Reverse()
{
	int n = StrLength();
	char c;
	for (int i = 0; i < n / 2 ; i++) {
		c = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = c;
	}
}

void String::SubString(String& Sub, int pos, int len)
{
	if (len <= 0 || pos < 0 || pos + len > StrLength()) {
		cout << "Error!" << endl;
		return;
	}
	int i = 0;
	while (i < len) {
		Sub[i] = a[i + pos];
		i++;
	}
	Sub[i] = '\0';

}

int String::Index(String& P,int pos)const
{
	int m = P.StrLength();
	int n = StrLength();
	if (pos > n - m || pos < 0 || m == 0 || n == 0) return -1;    //明显失败预判
	int i = pos, j = 0;                                           //起始查找位置设为pos
	while (j < m && i < n) {       
		if (a[i] == P[j]) { i++; j++; }       
		else { i -= j - 1; j = 0; }         
		if (j == m) return i - j;            
	}
	return -1;                             
}

void String::Replace(String& T, String& V)
{
	int m = T.StrLength(), n = V.StrLength();
	int i = Index(T, 0);
	while (i != -1) {
		StrDelete(i, m);
		StrInsert(i, V);
		i = Index(T, i + n);
	}
}

void String::StrInsert(int pos, String& T)
{
	int m = StrLength();
	int n = T.StrLength();
	if (pos<0 || pos>m) {
		cout << "Error!" << endl;
		return;
	}
	for (int i = 0; i < m - pos + 1; i++)
	{
		a[m - i + n] = a[m - i];
	}
	for (int j = 0; j < n; j++){
		a[pos + j] = T[j];
	}
}

void String::StrDelete(int pos, int len) {
	int n = StrLength();
	if (pos < 0 || len<0 || pos + len>StrLength()) {  
		cout << "Error!" << endl;
		return;
	}
	for (int i = 0; i < n - pos + 1; i++) {
		a[pos + i] = a[pos + i + len];
	}
}




