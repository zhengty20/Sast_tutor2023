#include<iostream>
using namespace std;
const int DEFAULT_SIZE = 100;
class String
{
private:
	char a[DEFAULT_SIZE];
public:
	//构造一个空串
	String() { a[0] = '\0'; }

	//复制构造
	String(const char* S);
	String(String& S);

	//销毁
	~String() {};

	//显示
	void ShowString()const;

	//复制
	void StrCopy(String& S);
	//void friend StrCopy(String& T, String& S);

	//清空
	void ClearString();
	//void friend ClearString(String& S);

	//判空
	bool StrEmpty()const;
	//bool friend StrEmpty(String& S);

	//比较
	int StrCompare(String& S)const;
	//int friend StrCompare(String& T, String& S);

	//求长
	int StrLength()const;
	//int friend StrLength(String& S);

	//串接
	void Concat(String& S);                       //将串S串接本串后
	void Concat(String& S1, String& S2);          //将S1，S2串接后的新串存至本串
	//void friend Concat(String& T, String& S1, String& S2);         

	//反转
	void Reverse();
	//void friend Reverse(String& S);

	//截取字串
	void SubString(String& Sub, int pos, int len);
	//void friend SubString(String& Sub, String& S, int pos, int len);

	//字串查找
	int Index(String& P, int pos)const;
	//int friend Index(String& T, String& P, int pos);

	//插入
	void StrInsert(int pos, String& T);
	//void StrInsert(String& S, int pos, String& T);

	//删除字串
	void StrDelete(int pos, int len);
	//void StrDelete(String& S, int pos, int len);

	//关键词替换
	void Replace(String& T, String& V);
	void friend Replace(String& S, String& T, String& V);

	//模式串匹配
	//BF
	int friend BruteForceMatch(String& T, String& P);
	//KMP
	int friend KMP_Match(String& T, String& P);
	void friend Next(String& T, int n[]);
	void friend Next_Pro(String& T, int n[]);
	//BM
	int friend BM_Match(String& T, String& P);
	void friend Build_BC(String& P, int bc[]);
	void friend Build_GS(String& P, int bc[]);
	int friend Horspool(String& T, String& P);

	//重载下标运算符
	char& operator[](int n);
};
